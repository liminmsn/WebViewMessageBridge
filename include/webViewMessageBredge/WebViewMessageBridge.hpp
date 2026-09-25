#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <Windows.h>

namespace WebViewMessageBridge {
	std::string WideToUtf8(const wchar_t* value);

	struct MessageData {
		std::string value;
	};

	struct Message {
		std::string id;
		std::string type;
		MessageData data;
	};

	enum class MessageEnum {
		Unknown,
		Info,
		Http,
		Client,
		Warning,
		Error
	};

	void from_json(const nlohmann::json& json, MessageData& data);
	void from_json(const nlohmann::json& json, Message& message);

	MessageEnum MessageEnumFromString(const std::string& type);
	std::string MessageEnumToString(MessageEnum type);

	using MessageHandler = std::function<void(Message&)>;
	class WebViewMessageBridge
	{
	public:
		WebViewMessageBridge() = default;
		~WebViewMessageBridge() = default;
		void Send(LPWSTR message);
		void SetMessageHandler(MessageHandler handler);
	private:
		MessageHandler messageHandler;
	};
}