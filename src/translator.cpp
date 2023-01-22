#include <iostream>
#include <array>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <list>
#include <fstream>

/*Returns a set of string elements*/
std::set<std::string> make_exit_commands()
{
    return std::set<std::string>{"q", "quit", "e", "exit"};
}

void add_command(std::map<std::string, std::string> &translator, std::list<std::pair<std::string, std::string>> &history)
{
    auto w1 = std::string{};
    auto w2 = std::string{};
    std::cin >> w1;
    std::cin >> w2;
    std::cout << w1 << " => " << w2 << std::endl;
    translator.insert_or_assign(w1, w2);
    history.push_back(std::pair<std::string, std::string>(w1, w2));
}

void print_command(const std::map<std::string, std::string> &translator)
{
    auto iter = translator.begin();
    while (iter != translator.end())
    {
        std::cout
            << ">>>  " << iter->first << " <=> " << iter->second << std::endl;
        ++iter;
    }
}

void save_command(const std::pair<std::string, std::string> &from_to_key, const std::list<std::pair<std::string, std::string>> &history)
{
    auto filename = std::string{};
    std::cin >> filename;
    std::ofstream ostrm(filename, std::ios::out);
    ostrm << from_to_key.first << " " << from_to_key.second << std::endl;
    for (auto elem : history)
    {
        ostrm << elem.first << "-" << elem.second << std::endl;
    }
}

void load_from_file(std::pair<std::string, std::string> &from_to_key, std::map<std::string, std::string> &map, std::list<std::pair<std::string, std::string>> &history, const std::string &filename)
{
    std::ifstream istrm(filename, std::ios::out);
    auto line = std::string{};
    std::string key;
    std::string value;

    std::getline(istrm, line);
    std::stringstream s(line);
    std::getline(s, key, ' ');
    std::getline(s, value, ' ');
    from_to_key.first = key;
    from_to_key.second = value;

    while (std::getline(istrm, line))
    {
        std::stringstream s(line);

        std::getline(s, key, '-');
        std::getline(s, value, '-');

        map.insert_or_assign(key, value);
        history.push_back(std::pair<std::string, std::string>(key, value));
    }
}

void remove_all_instances(std::map<std::string, std::string> &map, const std::string &instance)
{
    for (auto it = map.begin(); it != map.end();)
    {
        auto key = it->first;
        auto value = it->second;
        if (key == instance || value == instance)
        {
            it = map.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void remove_command(std::map<std::string, std::string> &translator)
{
    auto s = std::string{};
    std::cin >> s;
    remove_all_instances(translator, s);
}

void translate_command(const std::map<std::string, std::string> &translator)
{
    auto line = std::string{};
    std::getline(std::cin, line);

    // create a stream from the string
    std::stringstream s(line);
    std::string s2;
    auto vect = std::vector<std::string>{};
    for (std::string line; std::getline(s, line, ' ');)
    {
        vect.push_back(line); // store the string in s2
    }
    vect.erase(vect.begin());

    for (auto elem : vect)
    {
        auto iter = translator.find(elem);
        if (iter == translator.end())
        {
            std::cout << "???" << std::endl;
        }
        else
        {
            std::cout << iter->second << std::endl;
        }
    }
}

void load_command(std::pair<std::string, std::string> &from_to_key, std::map<std::string, std::string> &translator, std::list<std::pair<std::string, std::string>> &history)
{
    auto s = std::string{};
    std::cin >> s;
    load_from_file(from_to_key, translator, history, s);
}

void display_language(const std::pair<std::string, std::string> &from_to_key)
{
    std::cout << "(" << from_to_key.first << " => " << from_to_key.second << ")" << std::endl;
}

void load_history(std::list<std::pair<std::string, std::string>> &history, std::map<std::string, std::string> &translator)
{
    auto iter = translator.begin();
    while (iter != translator.end())
    {
        history.push_back(std::pair<std::string, std::string>(iter->first, iter->second));
        ++iter;
    }
}

void switch_language(const std::pair<std::string, std::string> &from_to_key, std::map<std::string, std::string> &translator, std::map<std::pair<std::string, std::string>, std::map<std::string, std::string>> &translators_stock, std::list<std::pair<std::string, std::string>> &history)
{
    history.clear();
    display_language(from_to_key);
    auto iter = translators_stock.find(from_to_key);
    if (iter != translators_stock.end())
    {
        translator = iter->second;
    }
    else
    {
        translator = std::map<std::string, std::string>{};
    }
    load_history(history, translator);
}

void update_stock(const std::pair<std::string, std::string> &from_to_key, std::map<std::string, std::string> &translator, std::map<std::pair<std::string, std::string>, std::map<std::string, std::string>> &translators_stock)
{
    translators_stock.insert_or_assign(from_to_key, translator);
}

int main(int argc, char **argv)
{
    // Initialization of the translation structure
    auto way_of_exit = make_exit_commands();
    auto translator = std::map<std::string, std::string>{};
    auto translators_stock = std::map<std::pair<std::string, std::string>, std::map<std::string, std::string>>{};
    auto history = std::list<std::pair<std::string, std::string>>{};
    std::pair<std::string, std::string> from_to_key = {"fr", "eng"};

    if (argc == 3)
    {
        from_to_key = {argv[1], argv[2]};
    }

    // Title of the app
    std::cout << std::endl
              << "== Start of the translator (" << from_to_key.first << " => " << from_to_key.second << ") ==" << std::endl;

    while (true)
    {
        auto line = std::string{};

        // Command name
        std::cin >> line;

        if (way_of_exit.find(line) != way_of_exit.end()) // Exit command
        {
            return 0;
        }
        else if (line == "add") // Add command
        {
            add_command(translator, history);
        }
        else if (line == "print") // Print command
        {
            print_command(translator);
        }
        else if (line == "save") // Save command
        {
            save_command(from_to_key, history);
        }
        else if (line == "load") // Load command
        {
            load_command(from_to_key, translator, history);
        }
        else if (line == "clear") // Clear command
        {
            translator.clear();
            history.clear();
        }
        else if (line == "remove") // Remove command
        {
            remove_command(translator);
        }
        else if (line == "translate") // Translate command
        {
            translate_command(translator);
        }
        else if (line == "from") // Translate command
        {
            update_stock(from_to_key, translator, translators_stock);
            std::cin >> from_to_key.first;
            switch_language(from_to_key, translator, translators_stock, history);
        }
        else if (line == "to") // Translate command
        {
            update_stock(from_to_key, translator, translators_stock);
            std::cin >> from_to_key.second;
            switch_language(from_to_key, translator, translators_stock, history);
        }
    }

    return 0;
}