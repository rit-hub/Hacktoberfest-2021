import unittest


def find_grant_cap(grantsArray, newBudget):
    grantsArray = sorted(grantsArray, reverse=True)
    i = len(grantsArray) - 1
    flag = False
    cap = float(newBudget)/len(grantsArray)
    newBudget = float(newBudget)

    while not flag:

        while cap > grantsArray[i]:
            newBudget -= grantsArray[i]
            i -= 1

        new_cap = newBudget/(i + 1)

        if cap == new_cap:
            flag = True

        cap = new_cap

    return cap



class Testing(unittest.TestCase):
    def test_find_grant_cap(self):
        self.assertEqual(find_grant_cap([2, 100, 50, 120, 1000], 190), 47)
        self.assertEqual(find_grant_cap([2,4], 3), 1.5)
        self.assertEqual(find_grant_cap([2,4,6], 3), 1)
        self.assertEqual(find_grant_cap([2,100,50,120,1000], 190), 47)
        self.assertEqual(find_grant_cap([2,100,50,120,167], 400), 128)
        self.assertEqual(find_grant_cap([21,100,50,120,130,110], 140), 23.8)
        self.assertEqual(find_grant_cap([210,200,150,193,130,110,209,342,117], 1530), 211)




if __name__ == '__main__':
    unittest.main()
