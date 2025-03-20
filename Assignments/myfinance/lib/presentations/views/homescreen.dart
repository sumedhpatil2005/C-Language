import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:myfinance/presentations/views/graphs_screen.dart';
import 'package:myfinance/presentations/views/history_screen.dart';
import 'package:myfinance/presentations/views/reminder_screen.dart';
import 'package:provider/provider.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'categories_screen.dart';
import 'package:myfinance/presentations/views/transaction_screen.dart';
import 'package:myfinance/presentations/views/income_screen.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({super.key});

  Future<void> _logout(BuildContext context) async {
    final confirmed = await showDialog<bool>(
      context: context,
      builder: (context) => AlertDialog(
        title: const Text('Logout'),
        content: const Text('Are you sure you want to log out?'),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(context, false),
            child: const Text('Cancel'),
          ),
          TextButton(
            onPressed: () => Navigator.pop(context, true),
            child: const Text('Logout'),
          ),
        ],
      ),
    );

    if (confirmed == true) {
      final prefs = await SharedPreferences.getInstance();
      await prefs.setBool('isLoggedIn', false); // Clear login state
      await FirebaseAuth.instance.signOut(); // Sign out from Firebase
      Navigator.pushReplacementNamed(
          context, '/login'); // Navigate to login screen
    }
  }

  @override
  Widget build(BuildContext context) {
    // Get the current user from Firebase Authentication
    final User? user = FirebaseAuth.instance.currentUser;
    final String userName =
        user?.displayName ?? 'User'; // Use 'User' as fallback

    return Scaffold(
      appBar: AppBar(
        iconTheme: IconThemeData(color: Colors.white),
        backgroundColor: Color.fromRGBO(83, 177, 117, 1),
        title: const Text(
          'My Finance',
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
      ),
      body: Column(
        children: [
          // Greeting with User's Name
          Padding(
            padding: const EdgeInsets.all(16.0),
            child: Align(
              alignment: Alignment.centerLeft,
              child: Text(
                'Hello, $userName!',
                style: const TextStyle(
                  fontSize: 24,
                  fontWeight: FontWeight.bold,
                ),
              ),
            ),
          ),
          // Display Income, Expense, and Remaining Balance
          Consumer<TransactionProvider>(
            builder: (context, transactionProvider, child) {
              // Check if the remaining balance is negative
              final bool isNegativeBalance =
                  transactionProvider.remainingBalance < 0;

              return Padding(
                padding: const EdgeInsets.all(16.0),
                child: Card(
                  elevation: 4,
                  child: Padding(
                    padding: const EdgeInsets.all(16.0),
                    child: Column(
                      children: [
                        const Text(
                          'Summary',
                          style: TextStyle(
                            fontSize: 18,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 16),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            const Text('Total Income:'),
                            Text(
                              'Rs. ${transactionProvider.totalIncome.toStringAsFixed(2)}',
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
                              'Rs. ${transactionProvider.totalExpenses.toStringAsFixed(2)}',
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
                              'Rs. ${transactionProvider.remainingBalance.toStringAsFixed(2)}',
                              style: TextStyle(
                                fontWeight: FontWeight.bold,
                                color: isNegativeBalance
                                    ? Colors.red // Red for negative balance
                                    : Colors
                                        .green, // Green for positive balance
                              ),
                            ),
                          ],
                        ),
                      ],
                    ),
                  ),
                ),
              );
            },
          ),
          Expanded(
            child: AddTransactionScreen(),
          ),
        ],
      ),
      drawer: Drawer(
        child: ListView(
          padding: EdgeInsets.zero,
          children: [
            const DrawerHeader(
              decoration: BoxDecoration(
                color: Color.fromRGBO(83, 177, 117, 1),
              ),
              child: Text(
                'My Finance',
                style: TextStyle(
                    color: Colors.white,
                    fontSize: 18,
                    fontWeight: FontWeight.bold),
              ),
            ),
            ListTile(
              title: const Text('Categories'),
              onTap: () {
                Navigator.of(context).pop();
                Navigator.of(context).push(MaterialPageRoute(
                  builder: (ctx) => const CategoriesScreen(),
                ));
              },
            ),
            ListTile(
              title: const Text('Add Income'),
              onTap: () {
                Navigator.of(context).pop();
                Navigator.of(context).push(MaterialPageRoute(
                  builder: (ctx) => AddIncomeScreen(),
                ));
              },
            ),
            ListTile(
              title: const Text('Set Reminder'),
              onTap: () {
                Navigator.of(context).pop();
                Navigator.of(context).push(MaterialPageRoute(
                  builder: (ctx) => const ReminderScreen(),
                ));
              },
            ),
            ListTile(
              title: const Text('Graphs'),
              onTap: () {
                Navigator.of(context).pop();
                Navigator.of(context).push(MaterialPageRoute(
                  builder: (ctx) => const GraphScreen(),
                ));
              },
            ),
            ListTile(
              title: const Text('History'),
              onTap: () {
                Navigator.of(context).pop();
                Navigator.of(context).push(MaterialPageRoute(
                  builder: (ctx) => const HistoryScreen(),
                ));
              },
            ),
            const Divider(), // Add a divider
            ListTile(
              leading: const Icon(
                Icons.logout,
                color: Colors.red,
              ),
              title: const Text(
                'Logout',
                style: TextStyle(color: Colors.red),
              ),
              onTap: () {
                Navigator.pop(context); // Close the drawer
                _logout(context); // Call the logout function
              },
            ),
          ],
        ),
      ),
    );
  }
}
