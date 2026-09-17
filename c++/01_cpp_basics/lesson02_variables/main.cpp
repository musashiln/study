#include <iostream>
#include <string>

int main() {
    std::string robot_name = "小车";
    int run_count = 3;
    double battery_voltage = 12.6;
    bool online = true;

    std::cout << "机器人名称：" << robot_name << std::endl;
    std::cout << "运行次数：" << run_count << std::endl;
    std::cout << "电池电压：" << battery_voltage << " V" << std::endl;
    std::cout << "是否在线：" << online << std::endl;

    return 0;
}
