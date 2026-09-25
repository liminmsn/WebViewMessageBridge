#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <Windows.h>

namespace WebViewMessageBridge {
	using nlohmann::json;

	std::string WideToUtf8(const wchar_t* value);
	struct Message {
		std::string id;
		std::string type;
		json value;
	};

	enum class MessageEnum {
		Unknown,
		Info,
		Http,
		Client,
		Warning,
		Error
	};

	void from_json(const json& json, Message& message);

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