import 'dart:io';

import 'package:flutter/material.dart';
import 'package:myfinance/data/models/category_model.dart';
import 'package:provider/provider.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';
import 'package:myfinance/data/models/transaction_model.dart';

class HistoryScreen extends StatelessWidget {
  const HistoryScreen({super.key});

  @override
  Widget build(BuildContext context) {
    final transactionProvider = Provider.of<TransactionProvider>(context);

    // Group transactions by month
    final Map<String, List<Transaction>> transactionsByMonth = {};
    for (var transaction in transactionProvider.transactions) {
      final monthYear = '${transaction.date.month}-${transaction.date.year}';
      if (!transactionsByMonth.containsKey(monthYear)) {
        transactionsByMonth[monthYear] = [];
      }
      transactionsByMonth[monthYear]!.add(transaction);
    }

    return Scaffold(
      appBar: AppBar(
        iconTheme: IconThemeData(color: Colors.white),
        backgroundColor: Color.fromRGBO(83, 177, 117, 1),
        title: const Text(
          'Transaction History',
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
      ),
      body: ListView(
        children: transactionsByMonth.entries.map((entry) {
          final monthYear = entry.key;
          final transactions = entry.value;

          // Calculate monthly summary
          final totalIncome = transactionProvider.incomes
              .where((income) =>
                  '${income.date.month}-${income.date.year}' == monthYear)
              .fold(0.0, (sum, income) => sum + income.amount);

          final totalExpenses = transactions.fold(
              0.0, (sum, transaction) => sum + transaction.amount);

          final remainingBalance = totalIncome - totalExpenses;

          return Card(
            margin: const EdgeInsets.all(8),
            child: ExpansionTile(
              title: Text(
                '${_getMonthName(int.parse(monthYear.split('-')[0]))} ${monthYear.split('-')[1]}',
                style: const TextStyle(
                  fontSize: 18,
                  fontWeight: FontWeight.bold,
                ),
              ),
              subtitle: Text(
                'Transactions: ${transactions.length}',
              ),
              children: [
                Padding(
                  padding: const EdgeInsets.all(16.0),
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      // Monthly Summary
                      const Text(
                        'Monthly Summary',
                        style: TextStyle(
                          fontSize: 16,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      const SizedBox(height: 8),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          const Text('Total Income:'),
                          Text(
                            'Rs. ${totalIncome.toStringAsFixed(2)}',
                            style: const TextStyle(
                              fontWeight: FontWeight.bold,
                            ),
                          ),
                        ],
                      ),
                      const SizedBox(height: 8),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          const Text('Total Expenses:'),
                          Text(
                            'Rs. ${totalExpenses.toStringAsFixed(2)}',
                            style: const TextStyle(
                              fontWeight: FontWeight.bold,
                            ),
                          ),
                        ],
                      ),
                      const SizedBox(height: 8),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          const Text('Remaining Balance:'),
                          Text(
                            'Rs. ${remainingBalance.toStringAsFixed(2)}',
                            style: TextStyle(
                              fontWeight: FontWeight.bold,
                              color: remainingBalance >= 0
                                  ? Colors.green
                                  : Colors.red,
                            ),
                          ),
                        ],
                      ),
                      const SizedBox(height: 16),
                      // List of Transactions
                      const Text(
                        'Transactions',
                        style: TextStyle(
                          fontSize: 16,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      const SizedBox(height: 8),
                      ...transactions.map((transaction) {
                        final category =
                            transactionProvider.categories.firstWhere(
                          (cat) => cat.id == transaction.categoryId,
                          orElse: () => Category(
                            id: 'default',
                            name: 'Unknown',
                            imagePath: null,
                          ), // Provide a default category if no match is found
                        );

                        // Debugging: Print the image path
                        print('Category Image Path: ${category.imagePath}');

                        return ListTile(
                          leading: category.imagePath != null &&
                                  File(category.imagePath!).existsSync()
                              ? ClipRRect(
                                  borderRadius: BorderRadius.circular(8),
                                  child:
                                      category.imagePath!.startsWith('assets/')
                                          ? Image.asset(
                                              category.imagePath!,
                                              width: 40,
                                              height: 40,
                                              fit: BoxFit.cover,
                                            )
                                          : Image.file(
                                              File(category.imagePath!),
                                              width: 40,
                                              height: 40,
                                              fit: BoxFit.cover,
                                            ),
                                )
                              : const Icon(Icons.category, size: 40),
                          title: Text(
                              'Amount: Rs${transaction.amount.toStringAsFixed(2)}'),
                          subtitle: Text(
                              'Category: ${category.name}\nDate: ${transaction.date.toString()}'),
                        );
                      }).toList(),
                    ],
                  ),
                ),
              ],
            ),
          );
        }).toList(),
      ),
    );
  }

  // Helper function to get month name from month number
  String _getMonthName(int month) {
    switch (month) {
      case 1:
        return 'January';
      case 2:
        return 'February';
      case 3:
        return 'March';
      case 4:
        return 'April';
      case 5:
        return 'May';
      case 6:
        return 'June';
      case 7:
        return 'July';
      case 8:
        return 'August';
      case 9:
        return 'September';
      case 10:
        return 'October';
      case 11:
        return 'November';
      case 12:
        return 'December';
      default:
        return '';
    }
  }
}
