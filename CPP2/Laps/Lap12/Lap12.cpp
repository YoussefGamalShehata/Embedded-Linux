#include <iostream>
#include <string>
int main()
{
    std::string text = "The cycle of life is a cycle of cycles.";
    std::string search_str = "cycle";
    std::string replace_str = "circle";
    /*************************************/
    /************ Replace cycle with circle******************/
    /*************************************/
    int pos = 0;
    while ((pos = text.find(search_str, pos)) != std::string::npos)
    {
        text.replace(pos, search_str.length(), replace_str);
        pos += replace_str.length();
    }
    std::cout << text << std::endl;
    /*************************************/
    /************ Inserting great ***************************/
    /*************************************/
    pos = 0;
    pos = text.find(replace_str, pos);

    if (pos != std::string::npos)
    {
        text.insert(pos, "great ");
    }

    std::cout << text << std::endl;
    /*************************************/
    /************ Inserting never end ************************/
    /*************************************/
    pos = 0;
    int count = 0;
    search_str = "circle";
    replace_str = "never ends ";
    while ((pos = text.find(search_str, pos)) != std::string::npos)
    {
        count++;
        if (count == 2)
        {
            text.insert(pos, replace_str);
            break;
        }
        pos += search_str.length();
    }

    std::cout << text << std::endl;
    return 0;
}
