#include <print>

#include "adapter.h"
#include "builder.h"
#include "command.h"
#include "composit.h"
#include "factory.h"
#include "observer.h"
#include "observer_inventory.h"
#include "singleton.h"

int main() {
  // singleton pattern
  Printer* printer = Printer::getInstance();
  printer->print("Hello, world!");
  printer->print("This is a singleton printer.");

  // factory pattern
  AbstractFactorial* recursiveFactorial =
      FactorialFactory::createFactorial('R');
  int recursiveResult = recursiveFactorial->calculate(5);
  std::println("Recursive Result: {}", recursiveResult);

  AbstractFactorial* iterativeFactorial =
      FactorialFactory::createFactorial('I');
  int iterativeResult = iterativeFactorial->calculate(5);
  std::println("Iterative Result: {}", iterativeResult);

  delete recursiveFactorial;
  delete iterativeFactorial;

  // adapter pattern
  ClassAdapter classAdapter;
  int result = classAdapter.add(3, 4);
  std::println("Result: {}", result);

  Adaptee adaptee;
  ObjectAdapter objectAdapter(adaptee);
  result = objectAdapter.add(2, 4);
  std::println("Result: {}", result);

  // composit pattern
  CompositeShape compositeShape;
  Shape* rect = new Rectangle();
  Shape* tri = new Triangle();
  compositeShape.addShape(rect);
  compositeShape.addShape(tri);
  compositeShape.draw();

  delete rect;
  delete tri;

  // observer pattern
  MouseMoveSubject subject;
  MouseMoveLogger logger;
  MouseMovePrinter print;

  subject.attach(&logger);
  subject.attach(&print);

  MouseEvent event(42, 1337);
  subject.notify(event);
  subject.detach(&print);
  event = MouseEvent(1337, 42);
  subject.notify(event);

  // command pattern
  Invoker invoker;
  Command* openCommand = new OpenCommand();
  Command* saveCommand = new SaveCommand();
  invoker.setCommand(openCommand);
  invoker.executeCommand();
  invoker.setCommand(saveCommand);
  invoker.executeCommand();

  delete openCommand;
  delete saveCommand;

  // builder pattern
  AProduct aproduct = ProductBuilder()
                          .setName("Samsung TV")
                          .setDescription("A 55\" 4k smart TV from Samsung.")
                          .setPrice(89.99)
                          .setInventoryLevel(10)
                          .build();

  std::println("Product name: {}", aproduct.name());
  std::println("Product description: {}", aproduct.description());
  std::println("Product price: ${}", aproduct.price());
  std::println("Product inventory level: {}", aproduct.inventoryLevel());

  // observer pattern or product
  // // create a product with an initial inventory level of 10
  Product product =
      Product("Samsung TV", "A 55\" 4K smart TV from Samsung.", 899.99, 10);

  // // create a shopping cart and add the product to the cart
  Cart cart = Cart();
  cart.addProduct(&product);

  // // create a checkout object and add it as an observer of the product
  Checkout checkout = Checkout();
  product.attach(&checkout);

  // // reduce the inventory level of the product and observe the effect on the
  // // cart and checkout
  product.setInventoryLevel(9);
  checkout.addProduct(&product);
  std::println("Cart size: {}", cart.size());
  std::println("Total price: ${}", checkout.totalPrice());

  // // reduce the inventory level of the product to zero and observe the effect
  // on
  // // the cart and checkout
  product.setInventoryLevel(0);
  std::println("Cart size: {}", cart.size());
  std::println("Total price: ${}", checkout.totalPrice());

  return 0;
}
