import 'package:flutter/material.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:provider/provider.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';

class GraphScreen extends StatelessWidget {
  const GraphScreen({super.key});

  @override
  Widget build(BuildContext context) {
    final transactionProvider = Provider.of<TransactionProvider>(context);

    // Get expenses by category
    final expensesByCategory = transactionProvider.getExpensesByCategory();

    // Get income, expense, and balance by month
    final incomeExpenseBalanceByMonth =
        transactionProvider.getIncomeExpenseBalanceByMonth();

    return Scaffold(
      appBar: AppBar(
        iconTheme: IconThemeData(color: Colors.white),
        backgroundColor: Color.fromRGBO(83, 177, 117, 1),
        title: const Text(
          'Graphs',
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
      ),
      body: SingleChildScrollView(
        child: Column(
          children: [
            // Pie Chart for Expenses by Category
            const Padding(
              padding: EdgeInsets.all(16.0),
              child: Text(
                'Expenses by Category',
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
              ),
            ),
            SizedBox(
              height: 300,
              child: SfCircularChart(
                series: <CircularSeries>[
                  PieSeries<MapEntry<String, double>, String>(
                    dataSource: expensesByCategory.entries.toList(),
                    xValueMapper: (MapEntry<String, double> entry, _) =>
                        entry.key,
                    yValueMapper: (MapEntry<String, double> entry, _) =>
                        entry.value,
                    dataLabelMapper: (MapEntry<String, double> entry, _) =>
                        entry.key, // Display category names
                    dataLabelSettings: const DataLabelSettings(
                      isVisible: true,
                      labelPosition: ChartDataLabelPosition
                          .outside, // Optional: Adjust label position
                    ),
                  ),
                ],
              ),
            ),
            const SizedBox(height: 20),
            // Bar Chart for Income, Expense, and Balance by Month
            const Padding(
              padding: EdgeInsets.all(16.0),
              child: Text(
                'Income, Expense, and Balance by Month',
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
              ),
            ),
            SizedBox(
              height: 300,
              child: SfCartesianChart(
                primaryXAxis: CategoryAxis(),
                primaryYAxis: NumericAxis(
                  edgeLabelPlacement: EdgeLabelPlacement
                      .shift, // Optional: Adjust Y-axis labels
                ),
                series: <CartesianSeries<dynamic, dynamic>>[
                  ColumnSeries<MapEntry<String, Map<String, double>>, String>(
                    dataSource: incomeExpenseBalanceByMonth.entries.toList(),
                    xValueMapper:
                        (MapEntry<String, Map<String, double>> entry, _) =>
                            entry.key,
                    yValueMapper:
                        (MapEntry<String, Map<String, double>> entry, _) =>
                            entry.value['income'] ?? 0,
                    name: 'Income',
                    color: Colors.green,
                    dataLabelSettings: const DataLabelSettings(
                      isVisible: true, // Enable data labels
                    ),
                  ),
                  ColumnSeries<MapEntry<String, Map<String, double>>, String>(
                    dataSource: incomeExpenseBalanceByMonth.entries.toList(),
                    xValueMapper:
                        (MapEntry<String, Map<String, double>> entry, _) =>
                            entry.key,
                    yValueMapper:
                        (MapEntry<String, Map<String, double>> entry, _) =>
                            entry.value['expense'] ?? 0,
                    name: 'Expense',
                    color: Colors.red,
                    dataLabelSettings: const DataLabelSettings(
                      isVisible: true, // Enable data labels
                    ),
                  ),
                  ColumnSeries<MapEntry<String, Map<String, double>>, String>(
                    dataSource: incomeExpenseBalanceByMonth.entries.toList(),
                    xValueMapper:
                        (MapEntry<String, Map<String, double>> entry, _) =>
                            entry.key,
                    yValueMapper:
                        (MapEntry<String, Map<String, double>> entry, _) =>
                            entry.value['balance'] ?? 0,
                    name: 'Balance',
                    color: Colors.blue,
                    dataLabelSettings: const DataLabelSettings(
                      isVisible: true, // Enable data labels
                    ),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
