import 'package:flutter/material.dart';
import 'package:myfinance/data/models/income_model.dart';
import 'package:myfinance/data/models/category_model.dart';
import 'package:myfinance/data/models/reminder_model.dart';
import 'package:myfinance/data/models/transaction_model.dart';

class TransactionProvider with ChangeNotifier {
  final List<Category> _categories = [];
  final List<Transaction> _transactions = [];
  final List<IncomeModel> _incomes = [];
  final List<ReminderModel> _reminders = [];
  List<Map<String, dynamic>> _pendingReminders = [];

  // Getter for pending reminders
  List<Map<String, dynamic>> get pendingReminders => _pendingReminders;

  List<Category> get categories => _categories;
  List<Transaction> get transactions => _transactions;
  List<IncomeModel> get incomes => _incomes;
  List<ReminderModel> get reminders => _reminders;

  void addCategory(String name, {String? imagePath}) {
    final newCategory = Category(
      id: DateTime.now().toString(),
      name: name,
      imagePath: imagePath,
    );
    _categories.add(newCategory);
    notifyListeners();
  }

  void addTransaction(String categoryId, double amount, DateTime date) {
    final newTransaction = Transaction(
      id: DateTime.now().toString(),
      categoryId: categoryId,
      amount: amount,
      date: date,
    );
    _transactions.add(newTransaction);
    notifyListeners();
  }

  void deleteTransaction(String id) {
    _transactions.removeWhere((transaction) => transaction.id == id);
    notifyListeners();
  }

  void addIncome(double amount, DateTime date) {
    final newIncome = IncomeModel(
      id: DateTime.now().toString(),
      amount: amount,
      date: date,
    );
    _incomes.add(newIncome);
    notifyListeners();
  }

  void addReminder(ReminderModel reminder) {
    _reminders.add(reminder);
    notifyListeners();
  }

  void deleteReminder(String id) {
    _reminders.removeWhere((reminder) => reminder.id == id);
    notifyListeners();
  }

  void markReminderAsCompleted(String id) {
    final reminder = _reminders.firstWhere((reminder) => reminder.id == id);
    reminder.isCompleted = true;
    notifyListeners();
  }

  double get totalIncome {
    return _incomes.fold(0, (sum, income) => sum + income.amount);
  }

  double get totalExpenses {
    return _transactions.fold(
        0, (sum, transaction) => sum + transaction.amount);
  }

  double get remainingBalance {
    return totalIncome - totalExpenses;
  }

  // Method to calculate expenses by category
  Map<String, double> getExpensesByCategory() {
    final Map<String, double> expensesByCategory = {};

    for (var transaction in _transactions) {
      final category = _categories.firstWhere(
        (cat) => cat.id == transaction.categoryId,
        orElse: () => Category(id: 'default', name: 'Unknown', imagePath: null),
      );

      expensesByCategory[category.name] =
          (expensesByCategory[category.name] ?? 0) + transaction.amount;
    }

    return expensesByCategory;
  }

  // Method to calculate income, expense, and balance by month
  Map<String, Map<String, double>> getIncomeExpenseBalanceByMonth() {
    final Map<String, Map<String, double>> monthlyData = {};

    // Group transactions by month
    for (var transaction in _transactions) {
      final monthYear =
          '${transaction.date.month}-${transaction.date.year}'; // Format: "1-2023"

      if (!monthlyData.containsKey(monthYear)) {
        monthlyData[monthYear] = {
          'income': 0.0,
          'expense': 0.0,
          'balance': 0.0,
        };
      }

      monthlyData[monthYear]!['expense'] =
          (monthlyData[monthYear]!['expense'] ?? 0) + transaction.amount;
    }

    // Group incomes by month
    for (var income in _incomes) {
      final monthYear = '${income.date.month}-${income.date.year}';

      if (!monthlyData.containsKey(monthYear)) {
        monthlyData[monthYear] = {
          'income': 0.0,
          'expense': 0.0,
          'balance': 0.0,
        };
      }

      monthlyData[monthYear]!['income'] =
          (monthlyData[monthYear]!['income'] ?? 0) + income.amount;
    }

    // Calculate balance for each month
    for (var month in monthlyData.keys) {
      final income = monthlyData[month]!['income'] ?? 0;
      final expense = monthlyData[month]!['expense'] ?? 0;
      monthlyData[month]!['balance'] = income - expense;
    }

    return monthlyData;
  }
}
