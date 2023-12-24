import pytest

from oop_lr01_task_04_03_03.deposit import BonusTimeDeposit


class TestBonusTimeDeposit:
    def test_init(self):
        """Тестирование инициализации объекта класса BonusTimeDeposit."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        assert deposit.name == 'Срочный Вклад'
        assert deposit._interest_rate == 5
        assert deposit._period_limit == (6, 18)
        assert deposit._sum_limit == (1000, 100000)
        assert deposit._bonus == {'percent': 1, 'sum': 10000}

    def test_str(self):
        """Тестирование метода __str__."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        assert str(deposit) == \
            'Наименование:       Срочный Вклад\n' \
            'Валюта:             руб.\n' \
            'Процентная ставка:  5\n' \
            'Срок (мес.):        [6; 18)\n' \
            'Сумма:              [1000; 100000)\n' \
            'Бонус (мин. сумма): 10000.00'

    def test_get_profit(self):
        """Тестирование метода get_profit."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        assert deposit.get_profit(10000, 6) == 10000 * 5 / 100 * 6 / 12

    def test_get_profit__with_bonus(self):
        """Тестирование метода get_profit с бонусом."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        assert deposit.get_profit(20000, 6) == 20000 * 5 / 100 * 6 / 12 * 1.01

    def test_get_profit__with_bonus__invalid_sum(self):
        """Тестирование метода get_profit с бонусом при неверной сумме."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit.get_profit(1000, 6)

    def test_get_profit__with_bonus__invalid_period(self):
        """Тестирование метода get_profit с бонусом при неверном сроке."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit.get_profit(10000, 18)

    def test_get_sum(self):
        """Тестирование метода get_sum."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        deposit.get_sum(10000, 6)

    def test_get_sum__with_bonus(self):
        """Тестирование метода get_sum с бонусом."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        deposit.get_sum(20000, 6)

    def test_get_sum__with_bonus__invalid_sum(self):
        """Тестирование метода get_sum с бонусом при неверной сумме."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit.get_sum(1000, 6)

    def test_get_sum__with_bonus__invalid_period(self):
        """Тестирование метода get_sum с бонусом при неверном сроке."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit.get_sum(10000, 18)

    def test_check_self__invalid_bonus(self):
        """Тестирование метода _check_self при неверном бонусе."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )
        deposit._bonus = {'foo': 1, 'sum': 100000}

        with pytest.raises(AssertionError):
            deposit._check_self()

    def test_check_user_params__invalid_sum(self):
        """Тестирование метода _check_user_params при неверной сумме."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=((10000, 100000)),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit._check_user_params(1000, 6)

    def test_check_user_params__invalid_period(self):
        """Тестирование метода _check_user_params при неверном сроке."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=((6, 18)),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit._check_user_params(10000, 18)

    def test_get_profit__invalid_sum(self):
        """Тестирование метода get_profit при неверной сумме."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=((6, 18)),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit.get_profit(1000, 6)

    def test_get_profit__invalid_period(self):
        """Тестирование метода get_profit при неверном сроке."""
        deposit = BonusTimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=((6, 18)),
            sum_limit=(10000, 100000),
            bonus={'percent': 1, 'sum': 10000},
        )

        with pytest.raises(AssertionError):
            deposit.get_profit(10000, 18)
