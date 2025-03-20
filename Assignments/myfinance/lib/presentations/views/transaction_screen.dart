import 'package:flutter/material.dart';
import 'package:myfinance/data/models/category_model.dart';
import 'package:provider/provider.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';
import 'dart:io';

class AddTransactionScreen extends StatelessWidget {
  final _formKey = GlobalKey<FormState>();
  String? _selectedCategoryId;
  double? _amount;
  DateTime? _date;

  AddTransactionScreen({super.key});

  @override
  Widget build(BuildContext context) {
    final transactionProvider = Provider.of<TransactionProvider>(context);

    return Scaffold(
      appBar: AppBar(
        backgroundColor: Color.fromRGBO(83, 177, 117, 1),
        title: const Text(
          'Expenses',
          style: const TextStyle(
              fontSize: 24, fontWeight: FontWeight.bold, color: Colors.white),
        ),
      ),
      body: Column(
        children: [
          // Pending Reminders Section (Visible only if there are reminders)
          if (transactionProvider.reminders.any((reminder) =>
              !reminder.isCompleted)) // Check if there are pending reminders
            Column(
              children: [
                const Padding(
                  padding: EdgeInsets.all(16.0),
                  child: Text(
                    'Pending Reminders',
                    style: const TextStyle(
                      fontSize: 24,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                ),
                // Use a fixed height for the reminders list
                SizedBox(
                  height: 200, // Adjust the height as needed
                  child: ListView.builder(
                    itemCount: transactionProvider.reminders.length,
                    itemBuilder: (context, index) {
                      final reminder = transactionProvider.reminders[index];
                      if (reminder.isCompleted) {
                        return const SizedBox
                            .shrink(); // Skip completed reminders
                      }

                      return ListTile(
                        tileColor: const Color.fromRGBO(83, 177, 117, 1),
                        title: Text(reminder.title),
                        subtitle: Text(
                            'Amount: Rs. ${reminder.amount.toStringAsFixed(2)}\nDay: ${reminder.dayOfMonth}'),
                        trailing: Checkbox(
                          value: reminder.isCompleted,
                          onChanged: (value) {
                            // Mark the reminder as completed
                            transactionProvider
                                .markReminderAsCompleted(reminder.id);

                            // Add the amount to expenses
                            transactionProvider.addTransaction(
                              'reminder_category_id', // Replace with your category ID
                              reminder.amount,
                              DateTime.now(),
                            );
                          },
                        ),
                      );
                    },
                  ),
                ),
              ],
            ),
          // List of Transactions
          const Padding(
            padding: EdgeInsets.all(16.0),
            child: Text(
              'Transactions',
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
          ),
          // Use Expanded for the transactions list
          Expanded(
            child: ListView.builder(
              itemCount: transactionProvider.transactions.length,
              itemBuilder: (context, index) {
                final transaction = transactionProvider.transactions[index];
                final category = transactionProvider.categories.firstWhere(
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
                  leading: category.imagePath != null
                      ? ClipRRect(
                          borderRadius: BorderRadius.circular(8),
                          child: category.imagePath!.startsWith('assets/')
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
                  trailing: IconButton(
                    icon: const Icon(Icons.delete, color: Colors.red),
                    onPressed: () {
                      // Call the delete method in the provider
                      transactionProvider.deleteTransaction(transaction.id);
                    },
                  ),
                );
              },
            ),
          ),
        ],
      ),
      // Floating Action Button to Open Bottom Sheet
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          _showAddTransactionBottomSheet(context, transactionProvider);
        },
        backgroundColor: const Color.fromRGBO(83, 177, 117, 1),
        child: const Icon(
          Icons.add,
          color: Colors.white,
        ),
      ),
    );
  }

  // Function to Show Bottom Sheet
  void _showAddTransactionBottomSheet(
      BuildContext context, TransactionProvider transactionProvider) {
    showModalBottomSheet(
      context: context,
      isScrollControlled: true, // Allows the bottom sheet to take up more space
      builder: (context) {
        return Padding(
          padding: EdgeInsets.only(
            bottom:
                MediaQuery.of(context).viewInsets.bottom, // Adjust for keyboard
          ),
          child: Form(
            key: _formKey,
            child: SingleChildScrollView(
              child: Column(
                mainAxisSize: MainAxisSize.min,
                children: [
                  const SizedBox(height: 16),
                  const Text(
                    'Add Transaction',
                    style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                  ),
                  const SizedBox(height: 16),
                  SizedBox(
                    width: 350,
                    child: DropdownButtonFormField(
                      items: transactionProvider.categories.map((category) {
                        return DropdownMenuItem(
                          value: category.id,
                          child: Row(
                            children: [
                              if (category.imagePath != null)
                                ClipRRect(
                                  borderRadius: BorderRadius.circular(8),
                                  child:
                                      category.imagePath!.startsWith('assets/')
                                          ? Image.asset(
                                              category.imagePath!,
                                              width: 30,
                                              height: 30,
                                              fit: BoxFit.cover,
                                            )
                                          : Image.file(
                                              File(category.imagePath!),
                                              width: 30,
                                              height: 30,
                                              fit: BoxFit.cover,
                                            ),
                                )
                              else
                                const Icon(Icons.category, size: 30),
                              const SizedBox(width: 8),
                              Text(category.name),
                            ],
                          ),
                        );
                      }).toList(),
                      onChanged: (value) {
                        _selectedCategoryId = value;
                      },
                      decoration: const InputDecoration(labelText: 'Category'),
                      validator: (value) {
                        if (value == null) {
                          return 'Please select a category';
                        }
                        return null;
                      },
                    ),
                  ),
                  const SizedBox(height: 16),
                  SizedBox(
                    width: 300,
                    child: TextFormField(
                      decoration: InputDecoration(
                          enabledBorder: OutlineInputBorder(
                              borderSide: const BorderSide(
                                  color: Colors.grey, width: 1.5),
                              borderRadius: BorderRadius.circular(10)),
                          labelText: 'Amount'),
                      keyboardType: TextInputType.number,
                      validator: (value) {
                        if (value == null || value.isEmpty) {
                          return 'Please enter an amount';
                        }
                        if (double.tryParse(value) == null) {
                          return 'Please enter a valid number';
                        }
                        return null;
                      },
                      onSaved: (value) {
                        _amount = double.parse(value!);
                      },
                    ),
                  ),
                  const SizedBox(height: 16),
                  SizedBox(
                    width: 250,
                    child: TextButton(
                      style: const ButtonStyle(
                          backgroundColor: WidgetStatePropertyAll(
                        Color.fromRGBO(83, 177, 117, 1),
                      )),
                      child: const Text(
                        'Select Date',
                        style: TextStyle(color: Colors.white),
                      ),
                      onPressed: () async {
                        final selectedDate = await showDatePicker(
                          context: context,
                          initialDate: DateTime.now(),
                          firstDate: DateTime(2020),
                          lastDate: DateTime.now(),
                        );
                        if (selectedDate != null) {
                          _date = selectedDate;
                        }
                      },
                    ),
                  ),
                  const SizedBox(height: 16),
                  SizedBox(
                    width: 250,
                    child: ElevatedButton(
                      style: ElevatedButton.styleFrom(
                          backgroundColor:
                              const Color.fromRGBO(83, 177, 117, 1),
                          shape: RoundedRectangleBorder(
                              borderRadius: BorderRadius.circular(10))),
                      child: const Text(
                        'Add Transaction',
                        style: TextStyle(
                            color: Colors.white, fontWeight: FontWeight.bold),
                      ),
                      onPressed: () {
                        if (_formKey.currentState!.validate()) {
                          _formKey.currentState!.save();
                          if (_selectedCategoryId == null ||
                              _amount == null ||
                              _date == null) {
                            ScaffoldMessenger.of(context).showSnackBar(
                              const SnackBar(
                                  content: Text('Please fill all fields')),
                            );
                            return;
                          }
                          transactionProvider.addTransaction(
                            _selectedCategoryId!,
                            _amount!,
                            _date!,
                          );
                          Navigator.of(context).pop(); // Close the bottom sheet
                        }
                      },
                    ),
                  ),
                  const SizedBox(height: 16),
                ],
              ),
            ),
          ),
        );
      },
    );
  }
}
