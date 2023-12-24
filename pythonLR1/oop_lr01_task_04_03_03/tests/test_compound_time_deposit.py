from oop_lr01_task_04_03_03.deposit import CompoundTimeDeposit


class TestCompoundTimeDeposit:
    def test_str(self):
        """Тестирование метода __str__."""
        deposit = CompoundTimeDeposit(
            name='Сохраняй',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        assert str(deposit) == \
            'Наименование:       Сохраняй\n' \
            'Валюта:             руб.\n' \
            'Процентная ставка:  5\n' \
            'Срок (мес.):        [6; 18)\n' \
            'Сумма:              [1000; 100000)\n' \
            'Капитализация %   : Да'

    def test_get_profit(self):
        """Тестирование метода get_profit."""
        deposit = CompoundTimeDeposit(
            name='Сохраняй',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        assert deposit.get_profit(1000, 6) == 1000 * (1 + 5 / 100 / 12) ** 6 - 1000