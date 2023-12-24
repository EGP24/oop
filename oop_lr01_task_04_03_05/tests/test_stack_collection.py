import pytest

from oop_lr01_task_04_03_04.stack import Stack
from oop_lr01_task_04_03_05.stack_collection import StackCollection


class TestStackCollection:
    def test_init(self):
        """Тестирование инициализации объекта класса StackCollection."""
        # act
        stack_collection = StackCollection()

        # assert
        assert stack_collection._data == []

    def test_init_with_data(self, stack):
        """Тестирование инициализации объекта класса StackCollection с параметром data."""
        # act
        stack_collection = StackCollection([stack])

        # assert
        assert stack_collection._data == [stack]

    def test_str(self, stack):
        """Тестирование метода __str__."""
        # arrange
        stack_collection = StackCollection([stack, stack])

        # act
        result = str(stack_collection)

        # assert
        assert result == '[\n\t[1, 2, 3],\n\t[1, 2, 3]\n]'

    def test_getitem(self, stack):
        """Тестирование метода __getitem__."""
        # arrange
        stack_collection = StackCollection([stack, stack])

        # act
        result = stack_collection[0]

        # assert
        assert result == stack

    def test_setitem(self, stack):
        """Тестирование метода __setitem__."""
        # arrange
        stack_collection = StackCollection([stack, Stack([1, 2, 3, 5])])

        # act
        stack_collection[1] = stack

        # assert
        assert stack_collection._data == [stack, stack]

    def test_delitem(self, stack):
        """Тестирование метода __delitem__."""
        # arrange
        stack_collection = StackCollection([stack, Stack([1, 2, 3, 5])])

        # act
        del stack_collection[1]

        # assert
        assert stack_collection._data == [stack]

    def test_add(self, stack):
        """Тестирование метода add."""
        # arrange
        stack_collection = StackCollection([stack])

        # act
        stack_collection.add(stack)

        # assert
        assert stack_collection._data == [stack, stack]

    def test_add__wrong_type_error(self):
        """Тестирование метода add с ошибкой."""
        # arrange
        stack_collection = StackCollection()
        data = 1

        # assert and act
        with pytest.raises(TypeError):
            stack_collection.add(data)

    def test_save(self, stack, tmp_path):
        """Тестирование метода save."""
        # arrange
        stack_collection = StackCollection([stack])
        filename = tmp_path / 'test.json'

        # act
        stack_collection.save(filename)

        # assert
        assert filename.read_text(encoding='utf-8') == '[[1, 2, 3]]'

    def test_load(self, stack, tmp_path):
        """Тестирование метода load."""
        # arrange
        stack_collection = StackCollection([stack])
        filename = tmp_path / 'test.json'
        stack_collection.save(filename)

        # act
        result = StackCollection.load(filename)

        # assert
        assert result._data == [stack]
