//
// Created by Paul on 2020/12/18.
//

#ifndef PIZZASTORE1_PIZZASTORE_H
#define PIZZASTORE1_PIZZASTORE_H

#include "Pizza.h"
#include "PizzaIngredientFactory.h"

class PizzaStore {
public:
    PizzaStore() {

    }
    Pizza* orderPizza(string type) {
        Pizza* pizza = createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

    virtual Pizza* createPizza(string type) = 0;

private:
    Pizza* m_pizza;
};

class NYPizzaStore: public PizzaStore {
public:
    NYPizzaStore() {

    }
    Pizza * createPizza(string type) {
        if (type == "Cheese") {
            PizzaIngredientFactory* nyPizzaIngredientFactory = new NYPizzaIngredientFactory;
            return new CheesePizza(nyPizzaIngredientFactory);
        }
        else {
            // Other type pizza...
            return nullptr;
        }
    }
};

class ChicagoPizzaStore: public PizzaStore {
public:
    ChicagoPizzaStore() {

    }
    Pizza * createPizza(string type) {
        if (type == "Cheese") {
            PizzaIngredientFactory* chicagoPizzaIngredientFactory = new ChicagoPizzaIngredientFactory;
            return new CheesePizza(chicagoPizzaIngredientFactory);
        }
        else {
            // Other type pizza...
            return nullptr;
        }
    }
};

#endif //PIZZASTORE1_PIZZASTORE_H
