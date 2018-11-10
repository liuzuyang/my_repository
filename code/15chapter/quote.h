#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>
#include <algorithm>

namespace n_quo {
        class quote
        {
        public:
          //返回书的编号
          quote() = default;
          quote(const std::string &str, double pri) : book{str}, price{pri}{}
          const std::string &isbn() const{return book;}
          quote(const quote &qu) : book{qu.book}, price{qu.price}{
            std::cout << "调用quote的拷贝构造函数" << std::endl;
          }
          virtual ~quote(){ std::cout << "调用quote析构函数" << std::endl;}
          //返回书籍的价格
          virtual double net_price(std::size_t n) const{return n * price;}
          virtual void debug() const;

        private:
          std::string book;

        protected:
          double price{0.0};    //书籍的价格
        };

        void quote::debug() const
        {
          std::cout << book << " | " << price << " | ";
        }

        class disc_quote : public quote
        {
        public:
          disc_quote() = default;
          disc_quote(const std::string &str, double pri, std::size_t qua, double dis)
            : quote{str, pri}, quantity{qua}, discount{dis}{}
          disc_quote(const disc_quote &quo) :
            quote{quo}, quantity{quo.quantity}, discount{quo.discount}{
            std::cout << "调用disc_quote的拷贝构造函数" << std::endl;
          }
          double net_price(std::size_t) const = 0;
          ~disc_quote() override {std::cout << "调用disc_quote析构函数" << std::endl;}

        protected:
          std::size_t quantity{0};
          double discount{0.0};
        };

        class bulk_quote : public disc_quote
        {
        public:
          using disc_quote::disc_quote;
          bulk_quote(const bulk_quote &bul) : disc_quote{bul}{
            std::cout << "调用bulk_quote的拷贝构造函数" << std::endl;
          }
          ~bulk_quote() override{std::cout << "调用bulk_quote析构函数" << std::endl;}

          double net_price(std::size_t n) const override;
          void debug() const override;
        };

        void bulk_quote::debug() const
        {
          quote::debug();
          std::cout << quantity << " | " << discount << " | ";
        }

        double bulk_quote::net_price(std::size_t n) const
        {
          if (n >= quantity)
            {
              return (1 - discount) * (n * price);
            }
          else
            {
              return n * price;
            }
        }

        class dominate_quote : public disc_quote
        {
        public:
          using disc_quote::disc_quote;
          ~dominate_quote() override{}
          double net_price(std::size_t n) const override;

        };

        double dominate_quote::net_price(std::size_t n) const
        {
          if (n <= quantity)
            {
              return (1 - discount) * n * price;
            }
          else
            {
              return n * price;
            }
        }

        double print_total(std::ostream &os, const quote &quo, std::size_t n)
        {
          auto price = quo.net_price(n);
          os << "书籍编号: " << quo.isbn() << "\n";
          os << n << "本书总价: " << price << "\n";
          return price;
        }
}
#endif // QUOTE_H
