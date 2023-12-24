import pytest

from oop_lr01_task_04_03_02.заказ import Заказ


@pytest.fixture(name='заказ')
def create_заказ():
    заказ = Заказ()
    заказ.номер_заказа = 1
    return заказ