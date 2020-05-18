#include "Utils.h"

/**
 *  This file is the cpp file for the RUBIS_Util class.
 *  @file RUBIS_Util.cpp
 *  @brief cpp file for Engine-RUBIS_Util
 *  @author Seonghyeon Park
 *  @date 2020-03-31
 */

/**
 * @fn int greatest_common_divider
 * @brief get the greatest common divider of two numbers
 * @author Seonghyeon Park
 * @date 2020-05-12
 * @details 
 *  - None
 * @param int a
 * @param int b
 * @return a
 * @bug none
 * @warning none
 * @todo none
 */
int utils::greatest_common_divider(int a, int b)
{
	int c;
	
	while (b != 0)
	{	
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

/**
 * @fn int least_common_multiple
 * @brief get the greatest common divider of two numbers
 * @author Seonghyeon Park
 * @date 2020-05-12
 * @details 
 *  - None
 * @param int a
 * @param int b
 * @return a
 * @bug none
 * @warning none
 * @todo none
 */
int utils::least_common_multiple(int a, int b)
{
	return a * b / utils::greatest_common_divider(a, b);
}

int utils::least_common_multiple_array(std::vector<std::shared_ptr<Task>> *task_set)
{
	/**
	To be deleted code 
	Just for test
	std::cout << task_set->size() << std::endl;
	task_set->pop_back();
	std::cout << task_set->size() << std::endl;
	*/
	
	int lcm_of_array = 0;

	std::vector<std::shared_ptr<Task>>::iterator iter;
	for (iter = task_set->begin(); iter != task_set->end(); iter ++)
	{
		
		/**
		To be deleted code
		std::cout << iter->get()->get_task_name() << std::endl;
		*/

		
		if (lcm_of_array == 0)
		{
			/**
			 * To be delete code for testing
			 * std::cout << iter->get()->get_period() << std::endl; 
			 */
			
			lcm_of_array = iter->get()->get_period();
		}
		else
		{
			/**
			 * To be delete code for testing
			 * std::cout << iter->get()->get_period() << std::endl;
			 */ 
			lcm_of_array = utils::least_common_multiple(lcm_of_array, iter->get()->get_period());
		}
	}

	/**
	 * To be delete code for testing
	 * std::cout << "the last output is : " << lcm_of_array << std::endl;
	 */
	return lcm_of_array;
}

int utils::calculate_hyper_period(std::vector<std::shared_ptr<Task>> *task_set)
{
	int hyper_period = 0;
	hyper_period = utils::least_common_multiple_array(task_set);
	std::cout << "Hyper Period is : " << hyper_period << std::endl;
	return hyper_period;
}

/**
 * @fn void insert_can_msg()
 * @brief This function inserts CAN_Msg class into 'msg_list' list.
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @details 
 *  Each class is inserted into the list according to its time.
 * @param none
 * @return none
 * @bug none
 * @warning none
 * @todo none
 */
void utils::insert_can_msg(std::shared_ptr<CAN_message> input)
{
	// first element
	if (vectors::can_msg_vector.empty())
	{
		vectors::can_msg_vector.push_back(input);
		return;
	}

	std::vector<std::shared_ptr<CAN_message>>::iterator iter;
	for (iter = vectors::can_msg_vector.begin(); iter != vectors::can_msg_vector.end(); iter++)
	{
		if (iter->get()->get_time() > input.get()->get_time())
		{
			vectors::can_msg_vector.insert(iter, input);
			return;
		}
	}
	vectors::can_msg_vector.push_back(input);		// push target to the last position
}

void utils::exit_simulation(int signo)
{
	global_object::logger_thread->join();
	std::cout << "Simulation End\n" << SIGINT;
}