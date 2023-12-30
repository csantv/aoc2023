#include "solution.hpp"
#include "libs.hpp"

void Solution::day2p1()
{
    std::stringstream buffer {input};
    std::string line;
    const int id_offset = 5;
    while (std::getline(buffer, line)) {
        std::string_view view = line;
        // obtain id of game
        view.remove_prefix(id_offset);
        const auto idx = view.find(':');
        const auto str_id = view.substr(0, idx);
        // const auto game_id = std::atoi(str_id.data());
        view.remove_prefix(str_id.size() + 2);
        while (!view.empty()) {
            const auto semicolon_idx = view.find(';');
            std::string_view line = view;
            int chars_to_remove = 0;
            if (semicolon_idx != std::string_view::npos) {
                line = view.substr(0, semicolon_idx);
                chars_to_remove = 2;
            }
            //const auto line = view.substr(0, semicolon_idx);
            std::cout << line << '\n';
            view.remove_prefix(line.size() + chars_to_remove);
        }
        break;
    }
}
