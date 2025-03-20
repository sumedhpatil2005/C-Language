import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';

class AddIncomeScreen extends StatelessWidget {
  final _formKey = GlobalKey<FormState>();
  double? _amount;
  DateTime? _date;

  AddIncomeScreen({super.key});

  @override
  Widget build(BuildContext context) {
    final transactionProvider = Provider.of<TransactionProvider>(context);

    return Scaffold(
      appBar: AppBar(
        iconTheme: IconThemeData(color: Colors.white),
        backgroundColor: Color.fromRGBO(83, 177, 117, 1),
        title: const Text(
          'Add Income',
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Form(
          key: _formKey,
          child: Column(
            children: [
              TextFormField(
                decoration: InputDecoration(
                  labelText: 'Amount',
                  enabledBorder: OutlineInputBorder(
                    borderSide:
                        const BorderSide(color: Colors.grey, width: 1.5),
                    borderRadius: BorderRadius.circular(10),
                  ),
                  focusedBorder: OutlineInputBorder(
                    borderSide: const BorderSide(color: Colors.blue, width: 2),
                    borderRadius: BorderRadius.circular(10),
                  ),
                  errorBorder: OutlineInputBorder(
                    borderSide: const BorderSide(color: Colors.red, width: 1.5),
                    borderRadius: BorderRadius.circular(10),
                  ),
                  focusedErrorBorder: OutlineInputBorder(
                    borderSide: const BorderSide(color: Colors.red, width: 2),
                    borderRadius: BorderRadius.circular(10),
                  ),
                ),
                keyboardType: TextInputType.number,
                onSaved: (value) {
                  _amount = double.parse(value!);
                },
              ),
              const SizedBox(height: 16),
              TextButton(
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
              const SizedBox(height: 16),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    backgroundColor: const Color.fromRGBO(83, 177, 117, 1),
                    shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(10))),
                child: const Text(
                  'Add Income',
                  style: TextStyle(color: Colors.white),
                ),
                onPressed: () {
                  if (_formKey.currentState!.validate()) {
                    _formKey.currentState!.save();
                    transactionProvider.addIncome(_amount!, _date!);
                    Navigator.of(context).pop(); // Close the screen
                  }
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}
