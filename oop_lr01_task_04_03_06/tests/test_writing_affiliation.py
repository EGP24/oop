from oop_lr01_task_04_03_06.writing_affiliation import WritingAffiliation


class TestWritingAffiliation:
    def test_init(self):
        """Тестирование инициализации объекта класса WritingAffiliation."""
        # act
        writing_affiliation = WritingAffiliation(color='red', width=0.5)

        # assert
        assert writing_affiliation._color == 'red'
        assert writing_affiliation._width == 0.5

    def test_str(self):
        """Тестирование метода __str__."""
        # arrange
        writing_affiliation = WritingAffiliation(color='red', width=0.5)

        # act
        result = str(writing_affiliation)

        # assert
        assert result == 'Пишущая принадлежность'

    def test_color(self):
        """Тестирование свойства color."""
        # arrange
        writing_affiliation = WritingAffiliation(color='red', width=0.5)

        # act
        result = writing_affiliation.color

        # assert
        assert result == 'red'

    def test_width(self):
        """Тестирование свойства width."""
        # arrange
        writing_affiliation = WritingAffiliation(color='red', width=0.5)

        # act
        result = writing_affiliation.width

        # assert
        assert result == 0.5

    def test_write(self, capsys):
        """Тестирование метода write."""
        # arrange
        writing_affiliation = WritingAffiliation(color='red', width=0.5)

        # act
        writing_affiliation.write(text='text')

        # assert
        captured = capsys.readouterr()
        assert captured.out == 'С помощью "Пишущая принадлежность" написали "text"\n'

    def test_write__empty_text(self, capsys):
        """Тестирование метода write с пустым текстом."""
        # arrange
        writing_affiliation = WritingAffiliation(color='red', width=0.5)

        # act
        writing_affiliation.write(text='')

        # assert
        captured = capsys.readouterr()
        assert captured.out == ''
