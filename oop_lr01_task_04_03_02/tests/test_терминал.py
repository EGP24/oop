from contextlib import redirect_stdout
from contextlib import contextmanager
from io import StringIO
import sys

import pytest

from oop_lr01_task_04_03_02.заказ import Заказ
from oop_lr01_task_04_03_02.терминал import Терминал


@contextmanager
def redirect_stdin(new_stdin):
    old_stdin = sys.stdin
    sys.stdin = new_stdin
    try:
        yield
    finally:
        sys.stdin = old_stdin


class TestТерминал:
    def test_терминал_init(self):
        # arrange and act
        терминал = Терминал()

        # assert
        assert терминал.заказ is None
        assert терминал.отображать_меню is True

    def test_str_терминал(self):
        # arrange and act
        терминал = Терминал()

        # assert
        assert str(терминал) == 'PizzaHub, 1.0'

    def test_терминал_показать_меню(self):
        # arrange
        терминал = Терминал()
        out = StringIO()
        expected = (
            'PizzaHub\n'
            'Добро пожаловать!\n'
            '\n'
            'Меню:\n'
            '1. Пицца: Пипперони | Цена: 550.00 р.\n'
            '   Тесто: тонкое Соус: томатный\n'
            '   Начинка: томаты, колбаса салями, сыр моцарелла, перец чили, чеснок, '
            'сушённый базелик, оливковое масло\n'
            '2. Пицца: Барбекю | Цена: 625.00 р.\n'
            '   Тесто: тонкое Соус: барбекю\n'
            '   Начинка: томаты, говядина, сыр моцарелла, баклажан, шампиньоны, лук '
            'сладкий, солённый огурец\n'
            '3. Пицца: Дары моря | Цена: 700.00 р.\n'
            '   Тесто: тонкое Соус: чесночный\n'
            '   Начинка: семга, креветки, сыр моцарелла, мидии, маслины, лук красный\n'
            'Для выбора укажите цифру через <ENTER>.\n'
            'Для отмены заказа введите -1\n'
            'Для подтверждения заказа введите 0\n'
        )

        # act
        with redirect_stdout(out):
            терминал.показать_меню()

        # assert
        assert out.getvalue() == expected
        assert терминал.отображать_меню is False

    def test_терминал_показать_меню__меню_отключено(self):
        # arrange
        терминал = Терминал()
        терминал.отображать_меню = False
        out = StringIO()

        # act
        with redirect_stdout(out):
            терминал.показать_меню()

        # assert
        assert out.getvalue() == ''

    def test_терминал_обработать_команду_отмена(self):
        # arrange
        терминал = Терминал()
        терминал.заказ = 'заказ'
        терминал.отображать_меню = False
        out = StringIO()

        # act
        with redirect_stdout(out):
            терминал.обработать_команду(Терминал.КОМАНДА_ОТМЕНА_ЗАКАЗА)

        # assert
        assert out.getvalue() == 'Ваш заказ отменён\n'
        assert терминал.заказ is None

    def test_терминал_обработать_команду_подтверждение(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False
        out = StringIO()
        expected = (
            'Заказ подтвержен.\n'
            'Заказ №1\n'
            '\n'
            'Сумма заказа: 0.00\n'
            'Введите сумму: Оплата не удалась. Заказ будет отменен.\n'
            'Во время работы терминала произошла ошибка... pytest: reading from stdin '
            'while output is captured!  Consider using `-s`.\n'
        )

        # act
        with redirect_stdout(out):
            терминал.обработать_команду(Терминал.КОМАНДА_ПОДТВЕРЖДЕНИЕ_ЗАКАЗА)

        # assert
        assert out.getvalue() == expected

    def test_терминал_обработать_команду_подтверждение_успешно(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False

        inp = StringIO('0\n')
        out = StringIO()
        expected = (
            'Заказ подтвержен.\n'
            'Заказ №1\n'
            '\n'
            'Сумма заказа: 0.00\n'
            'Введите сумму: Вы внесли 0.00 р. Сдача: 0.00 р.\n'
            'Заказ №1 готов! Приятного аппетита!\n'
        )

        # act
        with redirect_stdout(out), redirect_stdin(inp):
            терминал.обработать_команду(Терминал.КОМАНДА_ПОДТВЕРЖДЕНИЕ_ЗАКАЗА)

        # assert
        assert out.getvalue() == expected

    def test_терминал_обработать_команду_подтверждение_успешно_с_сдачей(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False

        inp = StringIO('1000\n')
        out = StringIO()
        expected = (
            'Заказ подтвержен.\n'
            'Заказ №1\n'
            '\n'
            'Сумма заказа: 0.00\n'
            'Введите сумму: Вы внесли 1000.00 р. Сдача: 1000.00 р.\n'
            'Заказ №1 готов! Приятного аппетита!\n'
        )

        # act
        with redirect_stdout(out), redirect_stdin(inp):
            терминал.обработать_команду(Терминал.КОМАНДА_ПОДТВЕРЖДЕНИЕ_ЗАКАЗА)

        # assert
        assert out.getvalue() == expected

    def test_терминал_обработать_команду_подтверждение_успешно_с_сдачей_с_пробелом(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False

        inp = StringIO('1000\n')
        out = StringIO()
        expected = (
            'Заказ подтвержен.\n'
            'Заказ №1\n'
            '\n'
            'Сумма заказа: 0.00\n'
            'Введите сумму: Вы внесли 1000.00 р. Сдача: 1000.00 р.\n'
            'Заказ №1 готов! Приятного аппетита!\n'
        )

        # act
        with redirect_stdout(out), redirect_stdin(inp):
            терминал.обработать_команду(Терминал.КОМАНДА_ПОДТВЕРЖДЕНИЕ_ЗАКАЗА)

        # assert
        assert out.getvalue() == expected

    def test_терминал_обработать_команду_добавить_пиццу(self):
        # arrange
        терминал = Терминал()
        терминал.отображать_меню = False

        inp = StringIO('1\n')
        out = StringIO()
        expected = (
            'Пицца Пипперони добавлена!\n'
        )

        # act
        with redirect_stdout(out), redirect_stdin(inp):
            терминал.обработать_команду('1')

        # assert
        assert out.getvalue() == expected
        assert len(терминал.заказ.заказанные_пиццы) == 1

    def test_терминал_обработать_неизвестную_команду(self):
        # arrange
        терминал = Терминал()
        терминал.отображать_меню = False
        out = StringIO()

        # act
        with redirect_stdout(out):
            терминал.обработать_команду('17')

        # assert
        assert out.getvalue() == 'Не могу распознать команду! Проверьте ввод.\n'

    def test_терминал_обработать_команду__обработка_исключения(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False

        out = StringIO()
        expected = (
            'Заказ подтвержен.\n'
            'Заказ №1\n'
            '\n'
            'Сумма заказа: 0.00\n'
            'Введите сумму: Оплата не удалась. Заказ будет отменен.\n'
            'Во время работы терминала произошла ошибка... pytest: reading from stdin '
            'while output is captured!  Consider using `-s`.\n'
        )

        # act
        with redirect_stdout(out):
            терминал.обработать_команду(Терминал.КОМАНДА_ПОДТВЕРЖДЕНИЕ_ЗАКАЗА)

        # assert
        assert out.getvalue() == expected

    def test_терминал_рассчитать_сдачу(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False

        # act
        сдача = терминал.рассчитать_сдачу(1000)

        # assert
        assert сдача == 1000

    def test_терминал_рассчитать_сдачу__сумма_меньше_суммы_заказа(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False

        # assert and act
        pytest.raises(ValueError, терминал.рассчитать_сдачу, -1)

    def test_терминал_принять_оплату(self, заказ):
        # arrange
        терминал = Терминал()
        терминал.заказ = заказ
        терминал.отображать_меню = False

        inp = StringIO('1000\n')
        out = StringIO()

        # act
        with redirect_stdout(out), redirect_stdin(inp):
            терминал.принять_оплату()

        # assert
        assert out.getvalue() == 'Сумма заказа: 0.00\nВведите сумму: Вы внесли 1000.00 р. Сдача: 1000.00 р.\n'
