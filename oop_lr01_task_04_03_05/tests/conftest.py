import pytest

from oop_lr01_task_04_03_04.stack import Stack


@pytest.fixture(scope='function', name='stack')
def stack_fixture():
    """Фикстура для создания объекта класса Stack."""
    return Stack([1, 2, 3])