import pytest

from oop_lr01_task_04_03_06.pen import Pen


class TestPen:
    def test_pen_init(self):
        # arrange
        pen = Pen(color='red', width=0.5, remains=44)

        # assert and act
        assert pen._color == 'red'
        assert pen._width == 0.5
        assert pen._remains == 44

    @pytest.mark.parametrize('remains', (-1, 101))
    def test_pen_init__wrong_remains(self, remains):
        # assert and act
        pytest.raises(TypeError, Pen, color='red', width=0.5, remains=remains)

    def test_pen_write(self, capsys):
        # arrange
        pen = Pen(color='red', width=0.5, remains=44)

        # act
        pen.write('text')

        # assert
        captured = capsys.readouterr()
        assert pen._remains == 43.9
        assert captured.out == 'С помощью "Ручка" написали "text"\n'

    def test_pen_write__empty_text(self, capsys):
        # arrange
        pen = Pen(color='red', width=0.5, remains=44)

        # act
        pen.write('')

        # assert
        captured = capsys.readouterr()
        assert pen._remains == 44
        assert captured.out == ''

    def test_pen_write__no_remains(self, capsys):
        # arrange
        pen = Pen(color='red', width=0.5, remains=0)

        # act
        pen.write('text')

        # assert
        captured = capsys.readouterr()
        assert pen._remains == 0
        assert captured.out == 'Ручка закончилась\n'

    def test_pen_remains(self):
        # arrange
        pen = Pen(color='red', width=0.5, remains=44)

        # act
        result = pen.remains

        # assert
        assert result == 44