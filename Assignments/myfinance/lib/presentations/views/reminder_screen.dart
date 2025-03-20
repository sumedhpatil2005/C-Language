import 'package:flutter/material.dart';
import 'package:myfinance/services/notification_services.dart';
import 'package:provider/provider.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';
import 'package:myfinance/data/models/reminder_model.dart';

class ReminderScreen extends StatefulWidget {
  const ReminderScreen({super.key});

  @override
  _ReminderScreenState createState() => _ReminderScreenState();
}

class _ReminderScreenState extends State<ReminderScreen> {
  final _formKey = GlobalKey<FormState>();
  final TextEditingController _titleController = TextEditingController();
  final TextEditingController _bodyController = TextEditingController();
  final TextEditingController _amountController = TextEditingController();
  int _selectedDay = 1;

  Future<void> _checkAndRequestNotificationPermissions() async {
    final notificationService = NotificationService();
    final bool hasPermission =
        await notificationService.requestNotificationPermissions();

    if (!hasPermission) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Notification permission denied')),
      );
    }
  }

  @override
  void initState() {
    super.initState();
    _checkAndRequestNotificationPermissions();
  }

  @override
  Widget build(BuildContext context) {
    final transactionProvider = Provider.of<TransactionProvider>(context);

    return Scaffold(
      appBar: AppBar(
        iconTheme: const IconThemeData(color: Colors.white),
        backgroundColor: const Color.fromRGBO(83, 177, 117, 1),
        title: const Text(
          'Set Reminder',
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
      ),
      body: SingleChildScrollView(
        padding: EdgeInsets.only(
          bottom: MediaQuery.of(context).viewInsets.bottom,
        ),
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            children: [
              Form(
                key: _formKey,
                child: Column(
                  children: [
                    TextFormField(
                      controller: _titleController,
                      decoration: const InputDecoration(labelText: 'Title'),
                      validator: (value) {
                        if (value == null || value.isEmpty) {
                          return 'Please enter a title';
                        }
                        return null;
                      },
                    ),
                    TextFormField(
                      controller: _bodyController,
                      decoration:
                          const InputDecoration(labelText: 'Description'),
                      validator: (value) {
                        if (value == null || value.isEmpty) {
                          return 'Please enter a description';
                        }
                        return null;
                      },
                    ),
                    TextFormField(
                      controller: _amountController,
                      decoration: const InputDecoration(labelText: 'Amount'),
                      keyboardType: TextInputType.number,
                      validator: (value) {
                        if (value == null || value.isEmpty) {
                          return 'Please enter an amount';
                        }
                        return null;
                      },
                    ),
                    const SizedBox(height: 16),
                    const Text('Select Day of the Month:'),
                    Slider(
                      value: _selectedDay.toDouble(),
                      min: 1,
                      max: 31,
                      divisions: 30,
                      label: _selectedDay.toString(),
                      onChanged: (value) {
                        setState(() {
                          _selectedDay = value.toInt();
                        });
                      },
                    ),
                    const SizedBox(height: 16),
                    ElevatedButton(
                      style: ElevatedButton.styleFrom(
                        backgroundColor: const Color.fromRGBO(83, 177, 117, 1),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(10),
                        ),
                      ),
                      onPressed: () async {
                        if (_formKey.currentState!.validate()) {
                          final reminder = ReminderModel(
                            id: DateTime.now()
                                .millisecondsSinceEpoch
                                .toString(),
                            title: _titleController.text,
                            description: _bodyController.text,
                            dayOfMonth: _selectedDay,
                            amount: double.parse(_amountController.text),
                          );

                          // Add reminder to the provider
                          transactionProvider.addReminder(reminder);

                          // Schedule the monthly notification
                          await NotificationService()
                              .scheduleMonthlyNotification(
                            id: int.parse(reminder.id),
                            title: reminder.title,
                            body: reminder.description,
                            dayOfMonth: reminder.dayOfMonth,
                          );

                          // Show a success message
                          ScaffoldMessenger.of(context).showSnackBar(
                            const SnackBar(
                                content: Text('Reminder set successfully!')),
                          );

                          // Clear the form
                          _titleController.clear();
                          _bodyController.clear();
                          _amountController.clear();
                        }
                      },
                      child: const Text(
                        'Set Reminder',
                        style: TextStyle(color: Colors.white),
                      ),
                    ),
                    const SizedBox(height: 16),
                    // Button to trigger a reminder notification immediately
                    SizedBox(
                      width: 250,
                      child: ElevatedButton(
                        style: ElevatedButton.styleFrom(
                          backgroundColor:
                              const Color.fromRGBO(83, 177, 117, 1),
                          shape: RoundedRectangleBorder(
                            borderRadius: BorderRadius.circular(10),
                          ),
                        ),
                        onPressed: () async {
                          if (_titleController.text.isEmpty ||
                              _bodyController.text.isEmpty) {
                            ScaffoldMessenger.of(context).showSnackBar(
                              const SnackBar(
                                  content: Text(
                                      'Please enter a title and description')),
                            );
                            return;
                          }

                          // Show a notification immediately
                          await NotificationService().showNotificationNow(
                            title: _titleController.text,
                            body: _bodyController.text,
                          );

                          // Show a success message
                          ScaffoldMessenger.of(context).showSnackBar(
                            const SnackBar(
                                content:
                                    Text('Reminder notification triggered!')),
                          );
                        },
                        child: const Text(
                          'Trigger Reminder Now',
                          style: TextStyle(color: Colors.white),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
              const SizedBox(height: 16),
              const Text(
                'Reminders',
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
              ),
              // Use Expanded for the reminders list
              SizedBox(
                height: 200, // Adjust the height as needed
                child: ListView.builder(
                  itemCount: transactionProvider.reminders.length,
                  itemBuilder: (context, index) {
                    final reminder = transactionProvider.reminders[index];
                    return ListTile(
                      title: Text(reminder.title),
                      subtitle: Text(
                          'Amount: Rs. ${reminder.amount.toStringAsFixed(2)}\nDay: ${reminder.dayOfMonth}'),
                      trailing: IconButton(
                        icon: const Icon(Icons.delete, color: Colors.red),
                        onPressed: () {
                          transactionProvider.deleteReminder(reminder.id);
                        },
                      ),
                    );
                  },
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
