# WebViewMessageBridge 🚀

WebViewMessageBridge 是一个用于在本地应用与 WebView（内嵌浏览器）之间进行消息传递的轻量级桥接库。🔗

该仓库基于 C++20，使用 CMake + Ninja 构建器，面向 Windows（MSVC 工具链）。🛠️

特性 ✨
- 简单的消息发送与接收接口 📩
- 轻量无侵入，易于集成到现有项目 🧩
- 支持现代 C++（C++20）和常见构建流程 🔧

快速开始 ⚡
1. 克隆仓库：

   git clone https://github.com/liminmsn/WebViewMessageBridge.git

2. 创建构建目录并配置（需要 CMake >= 4.3.0，生成器建议 Ninja，使用 MSVC 工具链）：

   mkdir build && cd build
   cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ..

3. 构建：

   ninja

4. 运行或将生成的库/可执行文件集成到你的项目中。🏁

示例用法 🧭
- 头文件位于 include/ 下（例如：include/webViewMessageBredge/WebViewMessageBridge.hpp）。📂
- 在你的应用中包含头文件并按需调用桥接 API（具体 API 文档见代码注释）。🧾

开发与贡献 🤝
- 欢迎提交 Issue 或 Pull Request，描述问题或你想添加的功能。🐛➡️💡
- 遵循仓库的代码风格和提交规范，保持变更小而明确。🧹

许可协议 📜
本项目使用 MIT 许可证（如仓库中另有 LICENSE 文件，请以 LICENSE 为准）。🔓

联系方式 ✉️
- 若有问题可在 GitHub 仓库中提交 Issue。📮

感谢使用 WebViewMessageBridge！🎉
