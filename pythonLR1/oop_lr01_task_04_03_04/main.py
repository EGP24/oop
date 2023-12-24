# Программирование на языке высокого уровня (Python).
# Задание № 04_03_04. Вариант 17
#
# Выполнил: Переверза В.А.
# Группа: ПИН-б-о-22-1
# E-mail: vladislav.pereverza@gmail.com


from stack import Stack


if __name__ == "__main__":
    st = Stack([1, 2, 3])
    st.push(3)
    st.push(2)
    st.push(1)
    print('Стек:', st)

    last_element = st.pop()
    print('Извлеченный элемент:', last_element)

    print('Размер стека:', len(st))