class Base
{
  public:
    void pub_mem();
  protected:
    int prot_mem;
  private:
    char priv_mem;

}

struct Pub_Derv : public Base
{
  //保护成员对派生类来说可访问
  int f() {return prot_mem;}
  //私有成员对派生类不可访问
  char g() {return priv_mem;}
}

struct Priv_Derv : private Base
{
  //派生类的访问说明符不影响派生类的访问权限
  int f1() const {return prot_mem;
}
}
