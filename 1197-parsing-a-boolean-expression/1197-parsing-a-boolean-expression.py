class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        def eval_expr(index):
            current = expression[index]

            # Handle 't' and 'f'
            if current == 't':
                return True, index + 1
            if current == 'f':
                return False, index + 1

            # Handle NOT operation
            if current == '!':
                index += 2  # Skip '!('
                result, index = eval_expr(index)
                return not result, index + 1  # Skip ')'

            # Handle AND operation
            if current == '&':
                index += 2  # Skip '&('
                result = True
                first = True

                while expression[index] != ')':
                    if not first:
                        index += 1  # Skip ','
                    value, index = eval_expr(index)
                    result = result and value
                    first = False

                return result, index + 1  # Skip ')'

            # Handle OR operation
            if current == '|':
                index += 2  # Skip '|('
                result = False
                first = True

                while expression[index] != ')':
                    if not first:
                        index += 1  # Skip ','
                    value, index = eval_expr(index)
                    result = result or value
                    first = False

                return result, index + 1  # Skip ')'

            return False, index  # Should not reach here for valid expressions

        result, _ = eval_expr(0)
        return result


