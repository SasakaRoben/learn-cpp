#include <string>
#include <iostream>
#include <string_view>
#include <cassert>

class MyString {
private:
    std::string m_string {};

public:
    MyString(std::string_view string = {})
        :m_string { string }
    {}
    friend std::ostream& operator<<(std::ostream& out, const MyString& s) {
        out << s.m_string;
        return out;
    }

    MyString operator()(int start, int length) {
        assert(start >= 0);
        assert(start + length <= static_cast<int>(m_string.length()) && 
                "MyString::operator(int, int): Substring is out of range");
        
        return MyString { m_string.substr(
            static_cast<std::string::size_type>(start),
            static_cast<std::string::size_type>(length)
        )};
    }
};

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
