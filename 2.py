if __name__ == "__main__":
    class Animal:
        def __init__(self, name: str, age: int):
            """
            Конструктор базового класса Животное.

            Args:
                name (str): Имя животного.
                age (int): Возраст животного.
            """
            self.name = name
            self.age = age

        def __str__(self) -> str:
            """
            Возвращает строковое представление объекта.

            Returns:
                str: Строковое представление объекта.
            """
            return f"Животное: Имя животного:{self.name}. Возраст животного:{self.age} "

        def __repr__(self) -> str:
            """
            Возвращает строковое представление объекта.

            Returns:
                str: Строковое представление объекта.
            """
            return f"Животное({self.name}, {self.age})"

        def eat(self) -> None:
            """
            Метод, описывающий процесс питания животного.
            """
            print(f"{self.name} ест")

        def sleep(self) -> None:
            """
            Метод, описывающий процесс сна животного.
            """
            print(f"{self.name} спит")


    class Dog(Animal):
        def __init__(self, name: str, age: int, breed: str):
            """
            Конструктор дочернего класса Собака.

            Args:
                name (str): Имя собаки.
                age (int): Возраст собаки.
                breed (str): Порода собаки.
            """
            super().__init__(name, age)
            self.breed = breed

        def __str__(self) -> str:
            """
            Возвращает строковое представление объекта.

            Returns:
                str: Строковое представление объекта.
            """
            return f"Собака: {self.name}. Возраст: {self.age}. Порода: {self.breed}."

        def __repr__(self) -> str:
            """
            Возвращает строковое представление объекта.

            Returns:
                str: Строковое представление объекта.
            """
            return f"Собака({self.name}, {self.age}, {self.breed})"

        def bark(self) -> None:
            """
            Метод, описывающий голос собаки.
            """
            print(f"{self.name} лает")

        def sleep(self) -> None:
            """
            Перегрузка метода sleep из базового класса.

            Метод sleep у собаки будет отличаться от метода sleep у животного,
            поэтому мы его перегружаем.

            В данном случае, мы добавляем дополнительное сообщение о сне собаки.
            """
            print(f"{self.name} спит, прижавшись к хозяину")

    pass
