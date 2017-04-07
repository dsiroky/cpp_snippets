// http://stackoverflow.com/questions/11224838/prevent-user-from-derive-from-incorrect-crtp-base

template <class Derived>
class Base
{
  private:

    Base(){}; // prevent undesirable inheritance making ctor private
    friend Derived; // allow inheritance for Derived

  public :

    void call ()
    {
      static_cast<Derived *>(this)->call_impl();
    }
};
