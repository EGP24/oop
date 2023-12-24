# Программирование на языке высокого уровня (Python).
# Задание № 04_03_05. Вариант 17
#
# Выполнил: Переверза В.А.
# Группа: ПИН-б-о-22-1
# E-mail: vladislav.pereverza@gmail.com


from oop_lr01_task_04_03_05.stack_collection import StackCollection
from oop_lr01_task_04_03_04.stack import Stack

if __name__ == "__main__":
    sc = StackCollection()
    sc.add(Stack([1, 2, 3]))
    sc.add(Stack([4, 5, 6]))
    print('Коллекция стеков:', sc)

    sc[0] = sc[1].copy()
    print('Коллекция стеков:', sc)

    del sc[1]
    print('Коллекция стеков:', sc)
