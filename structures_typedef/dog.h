#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: struct for a dog's name, age and owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Prototype for Task 1 */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
