import pytest

from oop_lr01_task_04_03_03.deposit import TimeDeposit


class TestTimeDeposit:
    def test_init(self):
        """Тестирование инициализации объекта класса TimeDeposit."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        assert deposit.name == 'Срочный Вклад'
        assert deposit._interest_rate == 5
        assert deposit._period_limit == (6, 18)
        assert deposit._sum_limit == (1000, 100000)

    def test_str(self):
        """Тестирование метода __str__."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        assert str(deposit) == \
            'Наименование:       Срочный Вклад\n' \
            'Валюта:             руб.\n' \
            'Процентная ставка:  5\n' \
            'Срок (мес.):        [6; 18)\n' \
            'Сумма:              [1000; 100000)'

    def test_currency(self):
        """Тестирование свойства currency."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        assert deposit.currency == 'руб.'

    def test_check_self(self):
        """Тестирование метода _check_self."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        deposit._check_self()

    def test_check_user_params(self):
        """Тестирование метода _check_user_params."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        deposit._check_user_params(1000, 6)

    def test_get_profit(self):
        """Тестирование метода get_profit."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        assert deposit.get_profit(1000, 6) == 1000 * 5 / 100 * 6 / 12

    def test_get_sum(self):
        """Тестирование метода get_sum."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        deposit.get_sum(1000, 6)

    def test_check_self__invalid_interest_rate(self):
        """Тестирование метода _check_self при неверном проценте."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )
        deposit._interest_rate = 101

        with pytest.raises(AssertionError):
            deposit._check_self()

    def test_check_self__invalid_period_limit(self):
        """Тестирование метода _check_self при неверном сроке."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )
        deposit._period_limit = (18, 6)

        with pytest.raises(AssertionError):
            deposit._check_self()

    def test_check_self__invalid_sum_limit(self):
        """Тестирование метода _check_self при неверной сумме."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )
        deposit._sum_limit = (100000, 1000)

        with pytest.raises(AssertionError):
            deposit._check_self()

    def test_check_user_params__invalid_sum(self):
        """Тестирование метода _check_user_params при неверной сумме."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        with pytest.raises(AssertionError):
            deposit._check_user_params(100000, 6)

    def test_check_user_params__invalid_period(self):
        """Тестирование метода _check_user_params при неверном сроке."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(1000, 100000),
        )

        with pytest.raises(AssertionError):
            deposit._check_user_params(1000, 18)

    def test_get_profit__invalid_sum(self):
        """Тестирование метода get_profit при неверной сумме."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(100000, 1000000),
        )

        with pytest.raises(AssertionError):
            deposit.get_profit(1000, 6)

    def test_get_profit__invalid_period(self):
        """Тестирование метода get_profit при неверном сроке."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(100000, 1000000),
        )

        with pytest.raises(AssertionError):
            deposit.get_profit(100000, 18)

    def test_get_sum__invalid_sum(self):
        """Тестирование метода get_sum при неверной сумме."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(100000, 1000000),
        )

        with pytest.raises(AssertionError):
            deposit.get_sum(1000, 6)

    def test_get_sum__invalid_period(self):
        """Тестирование метода get_sum при неверном сроке."""
        deposit = TimeDeposit(
            name='Срочный Вклад',
            interest_rate=5,
            period_limit=(6, 18),
            sum_limit=(100000, 1000000),
        )

        with pytest.raises(AssertionError):
            deposit.get_sum(100000, 18)
