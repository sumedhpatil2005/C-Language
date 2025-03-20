class ReminderModel {
  final String id;
  final String title;
  final String description;
  final int dayOfMonth;
  final double amount;
  bool isCompleted;

  ReminderModel({
    required this.id,
    required this.title,
    required this.description,
    required this.dayOfMonth,
    required this.amount,
    this.isCompleted = false,
  });
}
