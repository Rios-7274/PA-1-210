#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
        << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== UNO ==" << std::endl;
    std::unique_ptr<List<Player>> table = makeList<Player>();
	table->addFront(new Player( 1, "Aiden"));
	table->addFront(new Player( 2, "Brooklyn"));
	table->addFront(new Player( 3, "Carlos"));
	table->addFront(new Player( 4, "Diana"));
	table->print();
    std::cout << std::endl << "== Player joins mid-order ==" << std::endl;
	table->addAnywhere(2, new Player(5,"Elias"));
	table->print();
    std::cout << std::endl << "== UNO reverse ==" << std::endl;
	table->reverse();
    table->print();
	std::cout << std::endl << "== Player leaves mid-order ==" << std::endl;
	table->deleteAnywhere(3);
    table->print();

    std::cout << std::endl << "== Table 2 ==" << std::endl;
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addFront(new Player(6, "Moose"));
    table2->addFront(new Player(7, "Piggy"));
    table2->addFront(new Player(8, "Baggins"));
	table2->print();
	std::cout << std::endl << "== Merge tables ==" << std::endl;
	table->concat(table2.get());
    table->print();

    return 0;
}
