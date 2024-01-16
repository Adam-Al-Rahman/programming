
#include <string>
#include <unordered_map>
#include <vector>

class MetaData {

public:
  std::string filename;
  std::string title;
  std::vector<std::string> tags;
  std::vector<std::string> aliases;
  std::string description;
  std::unordered_map<std::string, std::string> custom_metadata;

  MetaData(std::string filename, std::string title = "",
           std::vector<std::string> tags = {},
           std::vector<std::string> aliases = {}, std::string description = "",
           std::unordered_map<std::string, std::string> custom_metadata = {})
      : filename(filename), tags(tags), description(description),
        custom_metadata(custom_metadata){};

  bool operator==(const MetaData &to_compare_data)
      const { // use const because not to change member(class) data
    // i.e we cannot to
    // this->filename = filename + "habibi";
    return this->filename == to_compare_data.filename;
  }
};

class Node {
public:
  MetaData data;
  std::vector<Node *> children;

  /*
   * Perfrom preorder traversal of graph and tree
   * @param input: The input list that need to fill the node name
   */
  std::vector<MetaData> pre_order(std::vector<MetaData> &input) {

    input.push_back(data);

    if (!children.empty()) {
      for (Node *child : children) {
        child->pre_order(input);
      }
    }
    return input;
  };

  std::vector<MetaData> post_order(std::vector<MetaData> &input) {
    return input;
  };
  std::vector<MetaData> in_order(std::vector<MetaData> &input) {
    return input;
  };

  /*
   * @param input: The input list that need to fill the node name
   * @param order: In which order to traverse,
   *               options: {"pre", "post", "in"}
   */
  std::vector<MetaData> depth_first_search(std::vector<MetaData> &input,
                                           std::string order = "pre") {
    if (order == "in")
      return this->in_order(input);
    else if (order == "post")
      return this->post_order(input);
    return this->pre_order(input);
  }

  Node(MetaData data) : data(data){};
};

int main() {
  Node *graph = new Node(MetaData("introduction.md"));
  int a = 5;
  std::nullptr_t empty = nullptr;
}
