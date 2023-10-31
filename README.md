# hw_abstract_factory
Abstract factory
The main participants of the pattern:
Abstract Factory: This is an interface or abstract
a class that defines methods for creating a family of related objects.
Concrete Factory: Implementation of an abstract factory,
which creates specific objects according to the family.
Abstract Product: This is an interface or abstract
a class that defines the specification for the objects that are created by the factory.
Concrete Product: Implementation of a specific product,
which is created by a specific factory.
Assignment (part 1)
Develop a simple game engine that uses the "Abstract
factory" to create heroes and enemies in two different game worlds:
fantasy and science fiction.
Create abstract classes "Hero" and "Enemy", which will represent heroes and
enemies in the game. Create an abstract factory "GameFactory" that has methods
"createHero" and "createEnemy" to create heroes and enemies in the game.
Implement two different types of heroes ("Knight" and "Archer") and two different types
enemies ("Goblin" and "Witch") by subclassing from "Hero" and "Enemy".
Assignment (part 2)
Create two specific factories: "FantasyGameFactory" and
"SciFiGameFactory", which will implement an abstract factory and have
the ability to create different types of heroes and enemies in fantasy and sci-fi
fantasy worlds, respectively.
Create instances of factories and use them to create heroes and
enemies in every world. Display information about created heroes and enemies
on the screen Ensure that the client code can create heroes and enemies
without binding to specific types and without changing the code of factories or objects
heroes/enemies. End the rough life cycle of objects and release resources.
Write tests to check the correct operation of factories and facilities
heroes/enemies.
