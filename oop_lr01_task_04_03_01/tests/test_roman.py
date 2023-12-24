import pytest

from oop_lr01_task_04_03_01.roman import Roman


class TestRoman:
    def test_roman_init_from_arabic(self):
        """Тестирование инициализации объекта класса Roman."""
        # assert and act
        assert Roman(1).arabic == 1
        assert Roman(1)._arabic == 1

    def test_roman_init_from_roman(self):
        """Тестирование инициализации объекта класса Roman."""
        # assert and act
        assert Roman('I').arabic == 1
        assert Roman('I')._arabic == 1

    def test_roman_init_with_wrong_type(self):
        """Тестирование инициализации объекта класса Roman с неправильным типом."""
        # assert and act
        pytest.raises(TypeError, Roman, .1)

    def test_roman_init_with_wrong_value(self):
        """Тестирование инициализации объекта класса Roman с неправильным значением."""
        # assert and act
        pytest.raises(ValueError, Roman, 0)

    @pytest.mark.parametrize(('addend', 'result'), [(Roman(1), Roman(2)), (1, Roman(2))])
    def test_roman_add(self, addend, result):
        """Тестирование сложения объектов класса Roman."""
        # assert and act
        assert str(Roman(1) + addend) == str(result)

    def test_roman_add_with_wrong_type(self):
        """Тестирование сложения объектов класса Roman с неправильным типом."""
        # assert and act
        pytest.raises(TypeError, Roman(1).__add__, 'foo')

    @pytest.mark.parametrize(('subtrahend', 'result'), [(Roman(1), Roman(1)), (1, Roman(1))])
    def test_roman_sub(self, subtrahend, result):
        """Тестирование вычитания объектов класса Roman."""
        # assert and act
        assert str(Roman(2) - subtrahend) == str(result)

    def test_roman_sub_with_wrong_type(self):
        """Тестирование вычитания объектов класса Roman с неправильным типом."""
        # assert and act
        pytest.raises(TypeError, Roman(1).__sub__, 'foo')

    @pytest.mark.parametrize(('multiplier', 'result'), [(Roman(2), Roman(4)), (2, Roman(4))])
    def test_roman_mul(self, multiplier, result):
        """Тестирование умножения объектов класса Roman."""
        # assert and act
        assert str(Roman(2) * multiplier) == str(result)

    def test_roman_mul_with_wrong_type(self):
        """Тестирование умножения объектов класса Roman с неправильным типом."""
        # assert and act
        pytest.raises(TypeError, Roman(1).__mul__, 'foo')

    @pytest.mark.parametrize(('divider', 'result'), [(Roman(2), Roman(2)), (2, Roman(2))])
    def test_roman_div(self, divider, result):
        """Тестирование деления объектов класса Roman."""
        # assert and act
        assert str(Roman(4) / divider) == str(result)

    def test_roman_div_with_wrong_type(self):
        """Тестирование деления объектов класса Roman с неправильным типом."""
        # assert and act
        pytest.raises(TypeError, Roman(1).__truediv__, 'foo')

    def test_roman_div_by_zero(roman_div_):
        """Тестирование деления объектов класса Roman на ноль."""
        # assert and act
        pytest.raises(ZeroDivisionError, Roman(1).__truediv__, 0)

    @pytest.mark.parametrize(
        ('arabic', 'roman'),
        [
            (1, 'I'),
            (2, 'II'),
            (4, 'IV'),
            (9, 'IX'),
            (12, 'XII'),
            (15, 'XV'),
            (31, 'XXXI'),
            (37, 'XXXVII'),
        ]
    )
    def test_roman_str(self, arabic, roman):
        """Тестирование преобразования объекта класса Roman в строку."""
        # assert and act
        assert str(Roman(arabic)) == roman

    @pytest.mark.parametrize(
        ('roman', 'arabic'),
        [
            ('I', 1),
            ('II', 2),
            ('IV', 4),
            ('IX', 9),
            ('XII', 12),
            ('XV', 15),
            ('XXXI', 31),
            ('XXXVII', 37),
        ]
    )
    def test_roman_to_arabic(self, arabic, roman):
        """Тестирование преобразования римского числа в арабское."""
        # assert and act
        assert Roman.to_arabic(roman) == arabic

    def test_roman_to_arabic_with_wrong_type(self):
        """Тестирование преобразования римского числа в арабское с неправильным типом."""
        # assert and act
        pytest.raises(TypeError, Roman.to_arabic, 1)

    def test_roman_to_arabic_with_wrong_value(self):
        """Тестирование преобразования римского числа в арабское с неправильным значением."""
        # assert and act
        pytest.raises(ValueError, Roman.to_arabic, '0')

    def test_roman_to_arabic_with_wrong_symbol(self):
        """Тестирование преобразования римского числа в арабское с неправильным символом."""
        # assert and act
        pytest.raises(ValueError, Roman.to_arabic, 'A')

    @pytest.mark.parametrize('arabic', [-1, 0, 4000])
    def test_check_arabic(self, arabic):
        """Тестирование проверки арабского числа."""
        # assert and act
        pytest.raises(ValueError, Roman._Roman__check_arabic, arabic)
