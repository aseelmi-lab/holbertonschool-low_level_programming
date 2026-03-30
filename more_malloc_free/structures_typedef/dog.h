#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a struct that stores basic information of a dog
 * @name: first member, name of the dog
 * @age: second member, age of the dog
 * @owner: third member, owner of the dog
 *
 * Description: this structure is used to define a dog with its
 * name, age and owner's name.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
