/*                                                   PROXY PATTERN
A proxy, in its most general form, is a class functioning as an interface to something else. The proxy could interface to anything: 
a network connection, a large object in memory, a file, or some other resource that is expensive or impossible to duplicate. In short, 
a proxy is a wrapper or agent object that is being called by the client to access the real serving object behind the scenes. 
Use of the proxy can simply be forwarding to the real object, or can provide additional logic. In the proxy extra functionality can be provided,
 for example caching when operations on the real object are resource intensive, or checking preconditions before operations on the real object are 
 invoked. For the client, usage of a proxy object is similar to using the real object, because both implement the same interface.
 
 Remote Proxy[edit]
In distributed object communication, a local object represents a remote object (one that belongs to a different address space). 
The local object is a proxy for the remote object, and method invocation on the local object results in remote method invocation on the remote object.
 An example would be an ATM implementation, where the ATM might hold proxy objects for bank information that exists in the remote server.

 
 Virtual Proxy[edit]
In place of a complex or heavy object, a skeleton representation may be advantageous in some cases.
 When an underlying image is huge in size, it may be represented using a virtual proxy object, loading the real object on demand.

 Protection Proxy[edit]
A protection proxy might be used to control access to a resource based on access rights.
*/




class ICar {
public:
  virtual void DriveCar() = 0;
};

class Car : public ICar {
  void DriveCar() override {
    std::cout << "Car has been driven!";
  }
};

class ProxyCar : public ICar {
private:
  ICar* realCar = new Car();
  int _driver_age;

public:
  ProxyCar (const int driver_age) : _driver_age(driver_age) {}

  void DriveCar() {
    if (_driver_age > 16)
      realCar->DriveCar();
    else
      std::cout << "Sorry, the driver is too young to drive.";
  }

};

// How to use above Proxy class?
void main()
{
    ICar* car = new ProxyCar(16);

    car->DriveCar();

    delete car;

    car = new ProxyCar(25);
	
    car->DriveCar();

    delete car;
}