import 'package:flutter/material.dart';
import 'package:myfinance/data/models/category_model.dart';

class CategoryProvider with ChangeNotifier {
  final List<Category> _categories = [];

  List<Category> get categories => _categories;

  void addCategory(String name) {
    final newCategory = Category(
      id: DateTime.now().toString(),
      name: name,
    );
    _categories.add(newCategory);
    notifyListeners();
  }

  void removeCategory(String id) {
    _categories.removeWhere((category) => category.id == id);
    notifyListeners();
  }
}
