import pytest

from oop_lr01_task_04_03_04.stack import Stack


class TestStack:
    def test_init(self):
        """Тестирование инициализации объекта класса Stack."""
        # arrange
        stack = Stack()

        # assert and act
        assert stack._Stack__stack == []

    @pytest.mark.parametrize(
        ('items', 'expected'),
        [([1, 2, 3], [1, 2, 3]), ('[1, 2, 3]', [1, 2, 3])],
    )
    def test_init_with_items(self, items, expected):
        """Тестирование инициализации объекта класса Stack с параметром items."""
        # act
        stack = Stack(items)

        # assert
        assert stack._Stack__stack == expected

    def test_init_with_items_str_error(self):
        """Тестирование инициализации объекта класса Stack с параметром items типа str с ошибкой."""
        # arrange
        items = '1, 2, 3'

        # assert and act
        with pytest.raises(TypeError):
            Stack(items)

    def test_init__wrong_type_error(self):
        """Тестирование инициализации объекта класса Stack с параметром items неверного типа с ошибкой."""
        # arrange
        items = 1

        # assert and act
        with pytest.raises(TypeError):
            Stack(items)

    def test_push(self):
        """Тестирование метода push."""
        # arrange
        stack = Stack()

        # act
        stack.push(1)

        # assert
        assert stack._Stack__stack == [1]

    def test_pop(self, stack):
        """Тестирование метода pop."""
        # act
        result = stack.pop()

        # assert
        assert result == 3
        assert stack._Stack__stack == [1, 2]

    def test_peek(self, stack):
        """Тестирование метода peek."""
        # act
        result = stack.peek()

        # assert
        assert result == 3
        assert stack._Stack__stack == [1, 2, 3]

    def test_copy(self, stack):
        """Тестирование метода copy."""
        # act
        result = stack.copy()

        # assert
        assert result == stack
        assert result is not stack

    def test_save(self, tmp_path, stack):
        """Тестирование метода save."""
        # arrange
        filename = tmp_path / 'stack.json'

        # act
        stack.save(filename)

        # assert
        assert filename.read_text() == '[1, 2, 3]'

    def test_load(self, tmp_path, stack):
        """Тестирование метода load."""
        # arrange
        filename = tmp_path / 'stack.json'
        stack.save(filename)

        # act
        result = Stack.load(filename)

        # assert
        assert result == stack

    def test_from_string(self, stack):
        """Тестирование метода from_string."""
        # act
        result = Stack.from_string('[1, 2, 3]')

        # assert
        assert result == stack

    def test_str(self, stack):
        """Тестирование метода __str__."""
        # act
        result = str(stack)

        # assert
        assert result == '[1, 2, 3]'

    def test_repr(self, stack):
        """Тестирование метода __repr__."""
        # act
        result = repr(stack)

        # assert
        assert result == '[1, 2, 3]'

    def test_len(self, stack):
        """Тестирование метода __len__."""
        # act
        result = len(stack)

        # assert
        assert result == 3

    def test_bool(self, stack):
        """Тестирование метода __bool__."""
        # act
        result = bool(stack)

        # assert
        assert result is True

    def test_add(self, stack):
        """Тестирование метода __add__."""
        # act
        result = stack + 4

        # assert
        assert result == Stack([1, 2, 3, 4])

    def test_radd(self, stack):
        """Тестирование метода __radd__."""
        # act
        result = 4 + stack

        # assert
        assert result == Stack([1, 2, 3, 4])

    def test_eq(self, stack):
        """Тестирование метода __eq__."""
        # arrange
        stack1 = stack.copy()
        stack2 = stack.copy()

        # act
        result = stack1 == stack2

        # assert
        assert result is True

    def test_ne(self, stack):
        """Тестирование метода __ne__."""
        # arrange
        stack1 = stack.copy()
        stack2 = stack.copy()

        # act
        result = stack1 != stack2

        # assert
        assert result is False
