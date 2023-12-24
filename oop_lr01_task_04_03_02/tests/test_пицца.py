from contextlib import redirect_stdout
from io import StringIO

from oop_lr01_task_04_03_02.пицца import Пицца, ПиццаПепперони, ПиццаБарбекю, ПиццаДарыМоря


class TestПицца():
    def test_пицца_init(self):
        # arrange and act
        пицца = Пицца()

        # assert
        assert пицца.название == 'Заготовка'
        assert пицца.тесто == 'тонкое'
        assert пицца.соус == 'кечтуп'
        assert пицца.начинка == []
        assert пицца.цена == 0

    def test_пицца_str(self):
        # arrange and act
        пицца = Пицца()

        # assert and act
        assert str(пицца) == 'Пицца: Заготовка | Цена: 0.00 р.\n   Тесто: тонкое Соус: кечтуп\n   Начинка: '

    def test_пицца_подготовить(self):
        # arrange
        пицца = Пицца()
        out = StringIO()
        expected = 'Начинаю готовить пицуу Заготовка\n - замешиваю тонкое тесто...\n - добавляю соус: кечтуп...\n - и, конечно: ...\n'

        # act
        with redirect_stdout(out):
            пицца.подготовить()

        # assert
        assert out.getvalue() == expected

    def test_пицца_испечь(self):
        # arrange
        пицца = Пицца()
        out = StringIO()
        expected = 'Выпекаю пиццу... Готово!\n'

        # act
        with redirect_stdout(out):
            пицца.испечь()

        # assert
        assert out.getvalue() == expected

    def test_пицца_нарезать(self):
        # arrange
        пицца = Пицца()
        out = StringIO()
        expected = 'Нарезаю на аппетитные кусочки...\n'

        # act
        with redirect_stdout(out):
            пицца.нарезать()

        # assert
        assert out.getvalue() == expected

    def test_пицца_упаковать(self):
        # arrange
        пицца = Пицца()
        out = StringIO()
        expected = 'Упаковываю в фирменную упаковку и готово!\n'

        # act
        with redirect_stdout(out):
            пицца.упаковать()

        # assert
        assert out.getvalue() == expected


class TestПиццаПепперони():
    def test_init(self):
        # arrange and act
        пицца = ПиццаПепперони()

        # assert
        assert пицца.название == 'Пипперони'
        assert пицца.тесто == 'тонкое'
        assert пицца.соус == 'томатный'
        assert пицца.начинка == [
            'томаты',
            'колбаса салями',
            'сыр моцарелла',
            'перец чили',
            'чеснок',
            'сушённый базелик',
            'оливковое масло',
        ]
        assert пицца.цена == 550


class TestПиццаБарбекю():
    def test_init(self):
        # arrange and act
        пицца = ПиццаБарбекю()

        # assert
        assert пицца.название == 'Барбекю'
        assert пицца.тесто == 'тонкое'
        assert пицца.соус == 'барбекю'
        assert пицца.начинка == [
            'томаты',
            'говядина',
            'сыр моцарелла',
            'баклажан',
            'шампиньоны',
            'лук сладкий',
            'солённый огурец',
        ]
        assert пицца.цена == 625


class TestПиццаДарыМоря():
    def test_init(self):
        # arrange and act
        пицца = ПиццаДарыМоря()

        # assert
        assert пицца.название == 'Дары моря'
        assert пицца.тесто == 'тонкое'
        assert пицца.соус == 'чесночный'
        assert пицца.начинка == ['семга', 'креветки', 'сыр моцарелла', 'мидии', 'маслины', 'лук красный']
        assert пицца.цена == 700
