// JsonDemo.cpp : Defines the entry point for the application.
//
#include "JsonDemo.h"
#include <fstream>

#ifdef _MSC_VER
#include <windows.h>
#endif

#include <ppsyqm/json.hpp>
// for convenience
using json = ppsyqm::json;

int main(int argc, char ** argv)
{
	std::cout << "Hello CMake." << std::endl;
	setlocale(LC_ALL, "chs");
#ifdef _MSC_VER
	SetConsoleOutputCP(65001);
#endif
	try
	{
		// create object from string literal
		auto jsonStr1 = "{\"name\": \"中国\", \"happy\": true, \"pi\": 3.141 }"_json;
		auto jsonStr2 = R"(
		 {
			"name": "中国",
			"happy": true,
			"pi": 3.141
		 }
		)"_json;
		// explicit conversion to string
		int space_num = 0;
		std::string s1 = jsonStr1.dump(space_num);
		space_num = 4;
		std::string s2 = jsonStr2.dump(space_num);
		// serialization with pretty printing
		// pass in the amount of spaces to indent
		std::cout << s1 << std::endl;
		std::cout << s2 << std::endl;

		// parse explicitly
		auto j3 = json::parse(s1);
		std::cout << j3["name"].get<std::string>() << std::endl;

		auto j4 = json::parse(s2);
		std::cout << j3["happy"].get<bool>() << std::endl;

		{

			std::string str((std::istreambuf_iterator<char>(std::ifstream("test.json", std::ios::in | std::ios::binary))),	std::istreambuf_iterator<char>());
			auto j5 = json::parse(str);
			std::cout << j5["name"].get<std::string>() << std::endl;
		}
		{
			json con_json;
			con_json["aaa"] = "张三";
			std::cout << con_json.dump() << std::endl;
		}
		{
			std::string str((std::istreambuf_iterator<char>(std::ifstream("test.json", std::ios::in | std::ios::binary))), std::istreambuf_iterator<char>());
			auto j_file = json::parse(str);
			auto array_list = j_file["list"];
			if (array_list.is_array())
			{
				for (auto & it : array_list)
				{
					std::cout << it["test"].get<int>() << std::endl;
				}
			}
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
