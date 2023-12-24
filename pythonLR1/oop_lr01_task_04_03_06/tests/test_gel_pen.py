from oop_lr01_task_04_03_06.gel_pen import GelPen


class TestGelPen:
    def test_gel_pen_init(self):
        # arrange
        gel_pen = GelPen(color='red', width=0.5, remains=44)

        # assert and act
        assert gel_pen._color == 'red'
        assert gel_pen._width == 0.5
        assert gel_pen._remains == 44

