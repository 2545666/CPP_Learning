class A
{
    public:
    int i;
    protected:
    void f2();
    int j;
    private:
    int k;

}
class B: public A
{
   public:
   void f3();
   protected:
   void f4();
   private int m;
}
class D:private b
{
   public:
   void f5();
   private:
   int n;
}