class Transaction {
  final String id;
  final String categoryId;
  final double amount;
  final DateTime date;

  Transaction({
    required this.id,
    required this.categoryId,
    required this.amount,
    required this.date,
  });
}
