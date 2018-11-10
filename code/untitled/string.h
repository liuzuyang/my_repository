#ifndef STRING_H
#define STRING_H
#include <memory>
#include <iostream>
#include <cstring>

namespace test
{
    class String
    {
    public:
        String() = default;
        String(const char *str);
        String(const String &);
        String(String &&) noexcept;
        ~String();
        String &operator=(const String &);
        String &operator=(String &&) noexcept;
        friend void swap(String &, String &) noexcept;
        int size() const noexcept { return m_size; }
        friend std::ostream &operator<<(std::ostream &, const String &);
        friend bool operator==(const String &, const String &);
        const char &operator[](size_t) const;
        char &operator[](size_t);

    private:
        std::allocator<char> alloc;	//内存分配器
        void free();
        char *alloc_n_copy(const char *, size_t);
        char *m_str{ nullptr };
        int m_size{ 0 };
    };

    inline
    char *String::alloc_n_copy(const char *src, size_t n)
    {
        auto data = alloc.allocate(n);
        std::memcpy(data, src, n);
        return data;
    }

    inline
    void String::free()
    {
        alloc.deallocate(m_str, m_size);
    }

    String::~String()
    {
        free();
    }

    String::String(const char *str)

    {
        m_size = static_cast<int>(std::strlen(str)) + 1;
        m_str = alloc_n_copy(str, m_size);
    }

    String::String(const String &str)
    {
        m_str = alloc_n_copy(str.m_str, str.m_size);
        m_size = str.m_size;
        std::cout << "调用拷贝运算符: " << m_str << std::endl;
    }

    inline
    void swap(String &str1, String &str2) noexcept
    {
        using std::swap;
        swap(str1.m_size, str2.m_size);
        swap(str1.m_str, str2.m_str);
    }

    inline
    String &String::operator=(const String &str)
    {
        if (this != &str)
        {       //若不是自赋值
           m_str = alloc_n_copy(str.m_str, str.m_size) ;    //复制目标资源
           free();      //释放资源
           m_size = str.m_size;
        }
        std::cout << "调用赋值运算符: " << m_str << std::endl;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const String &str)
    {
        os << str.m_str;
        return os;
    }

    String &String::operator=(String &&str) noexcept
    {
        if (this != &str)
        {       //若不是自赋值
            free();     //释放资源
            m_str = nullptr;
            m_size = 0;
            swap(*this, str);
        }
        std::cout << "使用移动赋值运算符: " << m_str << std::endl;
        return *this;
    }

    String::String(String &&str) noexcept
    {
        swap(*this, str);
        std::cout << "使用移动构造函数运算符: " << m_str << std::endl;
    }

    bool operator==(const String &str1, const String &str2)
    {
        return !std::strcmp(str1.m_str, str2.m_str);
    }

    bool operator!=(const String &str1, const String &str2)
    {
        return !(str1 == str2);
    }

    char &String::operator[](size_t n)
    {
        return *(m_str + n);
    }

    const char &String::operator[](size_t n) const
    {
        return *(m_str + n);
    }
}
#endif // STRING_H
