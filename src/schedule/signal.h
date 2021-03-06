/**
 * schedule/signal.h
 * signals to wake up sleeping process
 */
#include <queue>
#include <mutex>

class process_t;

class signal_t {

public:

	signal_t();
	signal_t(int id);
	~signal_t();
	void notify(int data);
	void wait(process_t *proc);

private:

	std::mutex mut;
	std::queue<process_t*> proc;
	std::queue<int> que;
	int signal_id;
	bool check_keyboard_signal(int data, process_t *proc);
};

namespace signal_id {
	extern const int WAIT_EXIT;
	extern const int KEYBOARD;
}

void init_signal ();
void destroy_signal ();

/**
 * send/wait on a signal
 * @return : 0 ok
 *          -1 not valid signal id
 */ 
int send_signal(int signal_id, int data);
int wait_signal(int signal_id, process_t *proc);

int register_signal();

