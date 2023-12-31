#include "solution.hpp"
#include "libs.hpp"

auto split_str(const std::string& str, const std::string& delimiter) -> std::vector<std::string>
{
    using std::string;
    std::vector<string> result;
    string::size_type begin = 0;
    while (true) {
        const auto end = str.find(delimiter, begin);
        const auto token = str.substr(begin, end - begin);
        result.push_back(token);
        if (end == string::npos) {
            break;
        }
        begin = end + delimiter.length();
    }
    return result;
}

void Solution::day2p1()
{
    std::stringstream buffer {input};
    std::string line;
    const int id_offset = 5;
    const std::unordered_map<std::string, int> total_plays = {
        {"red", 12},
        {"green", 13},
        {"blue", 14}
    };
    int total = 0;
    while (std::getline(buffer, line)) {
        line.erase(0, id_offset);
        const auto id_idx = line.find(':');
        const auto str_id = line.substr(0, id_idx);
        const auto game_id = std::stoi(str_id);
        line.erase(0, id_idx + 2);
        const auto games = split_str(line, "; ");
        bool invalid = false;
        for (const auto& game: games) {
            if (invalid) {
                break;
            }
            const auto plays = split_str(game, ", ");
            for (const auto& play: plays) {
                const auto details = split_str(play, " ");
                const auto number = std::stoi(details.at(0));
                const auto& color = details.at(1);
                const auto max_num = total_plays.at(color);
                if (number > max_num) {
                    invalid = true;
                    break;
                }
            }
        }
        if (!invalid) {
            total += game_id;
        }
    }
    std::cout << total << "\n";
}

void Solution::day2p2()
{
    std::stringstream buffer {input};
    std::string line;
    std::uint64_t total = 0;
    while (std::getline(buffer, line)) {
        const auto id_idx = line.find(':');
        line.erase(0, id_idx + 2);
        const auto games = split_str(line, "; ");
        std::unordered_map<std::string, int> min_cubes = {
            {"red", 0},
            {"green", 0},
            {"blue", 0}
        };
        for (const auto& game: games) {
            const auto plays = split_str(game, ", ");
            for (const auto& play: plays) {
                const auto details = split_str(play, " ");
                const auto number = std::stoi(details.at(0));
                const auto& color = details.at(1);
                auto& cur_value = min_cubes.at(color);
                if (number > cur_value) {
                    cur_value = number;
                }
            }
        }
        std::uint64_t tmp = 1;
        for (const auto& [color, number]: min_cubes) {
            tmp *= number;
        }
        total += tmp;
    }
    std::cout << total << '\n';
}
