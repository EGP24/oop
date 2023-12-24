from oop_lr01_task_04_03_06.pencil import Pencil


class TestPencil:
    def test_init(self):
        """Тестирование инициализации объекта класса Pencil."""
        # act
        pencil = Pencil(color='red', width=0.5, length=44)

        # assert
        assert pencil._color == 'red'
        assert pencil._width == 0.5
        assert pencil._length == 44

    def test_str(self):
        """Тестирование метода __str__."""
        # arrange
        pencil = Pencil(color='red', width=0.5, length=44)

        # act
        result = str(pencil)

        # assert
        assert result == 'карандаш'

    def test_color(self):
        """Тестирование свойства color."""
        # arrange
        pencil = Pencil(color='red', width=0.5, length=44)

        # act
        result = pencil.color

        # assert
        assert result == 'red'

    def test_width(self):
        """Тестирование свойства width."""
        # arrange
        pencil = Pencil(color='red', width=0.5, length=44)

        # act
        result = pencil.width

        # assert
        assert result == 0.5

    def test_length(self):
        """Тестирование свойства length."""
        # arrange
        pencil = Pencil(color='red', width=0.5, length=44)

        # act
        result = pencil.length

        # assert
        assert result == 44

    def test_write(self, capsys):
        """Тестирование метода write."""
        # arrange
        pencil = Pencil(color='red', width=0.01, length=44)

        # act
        pencil.write(text='text')

        # assert
        captured = capsys.readouterr()
        assert pencil.width == 0.02
        assert captured.out == 'С помощью "Карандаш" написали "text"\n'

    def test_write__empty_text(self, capsys):
        """Тестирование метода write с пустым текстом."""
        # arrange
        pencil = Pencil(color='red', width=0.01, length=44)

        # act
        pencil.write(text='')

        # assert
        captured = capsys.readouterr()
        assert pencil.width == 0.01
        assert captured.out == ''

    def test_write__no_length(self, capsys):
        """Тестирование метода write с нулевой длиной."""
        # arrange
        pencil = Pencil(color='red', width=0.01, length=0)

        # act
        pencil.write(text='text')

        # assert
        captured = capsys.readouterr()
        assert pencil.width == 0.01
        assert captured.out == 'Карандаш закончился\n'

    def test_write__no_width(self, capsys):
        """Тестирование метода write с нулевой шириной."""
        # arrange
        pencil = Pencil(color='red', width=0.1, length=44)

        # act
        pencil.write(text='text')

        # assert
        captured = capsys.readouterr()
        assert pencil.width == 0.1
        assert captured.out == 'Карандаш затупился\n'

    def test_sharpen(self, capsys):
        """Тестирование метода sharpen."""
        # arrange
        pencil = Pencil(color='red', width=0.01, length=44)

        # act
        pencil.sharpen()

        # assert
        captured = capsys.readouterr()
        assert pencil.width == 0.01
        assert pencil.length == 43.9
        assert captured.out == 'Карандаш поточен\n'
