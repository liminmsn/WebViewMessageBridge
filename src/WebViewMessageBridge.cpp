#include "../include/webViewMessageBredge/WebViewMessageBridge.hpp"

namespace WebViewMessageBridge {
	std::string WideToUtf8(const wchar_t* value)
	{
		if (!value)
			return {};

		int size = WideCharToMultiByte(CP_UTF8, 0, value, -1, nullptr, 0, nullptr, nullptr);

		if (size <= 0)
			return {};

		std::string result(size - 1, '\0');

		WideCharToMultiByte(CP_UTF8, 0, value, -1, result.data(), size, nullptr, nullptr);

		return result;
	}

	void from_json(const nlohmann::json& json, MessageData& data)
	{
		data.value = json.value("message", "");
	}

	void from_json(const nlohmann::json& json, Message& message)
	{
		message.type = json.value("type", "");

		if (json.contains("data") && json["data"].is_object()) {
			message.data = json["data"].get<MessageData>();
		}
	}

	MessageEnum MessageEnumFromString(const std::string& type)
	{
		if (type == "info")    return MessageEnum::Info;
		if (type == "http")   return MessageEnum::Http;
		if (type == "client") return MessageEnum::Client;
		if (type == "warning") return MessageEnum::Warning;
		if (type == "error")  return MessageEnum::Error;

		return MessageEnum::Unknown;
	}

	std::string MessageEnumToString(MessageEnum type)
	{
		switch (type) {
		case MessageEnum::Http:    return "http";
		case MessageEnum::Client:  return "client";
		case MessageEnum::Info:    return "info";
		case MessageEnum::Warning: return "warning";
		case MessageEnum::Error:   return "error";
		default:                   return "unknown";
		}
	}

	void WebViewMessageBridge::SetMessageHandler(MessageHandler handler)
	{
		messageHandler = std::move(handler);
	}

	void WebViewMessageBridge::Send(LPWSTR message)
	{
		try {
			std::string jsonString = WideToUtf8(message);
			nlohmann::json json = nlohmann::json::parse(jsonString);
			Message message = json.get<Message>();
			messageHandler(message);
		}
		catch (const nlohmann::json::exception&) {
			// TODO: 处理非法 JSON
			auto Unknown = Message{
				"-1",
				MessageEnumToString(MessageEnum::Unknown),
				{"Json格式错误"}
			};
			messageHandler(Unknown);
		}
	}
}