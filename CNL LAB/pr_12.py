import socket

def get_host_by_ip(ip_address):
    try:
        host_name, _, _ = socket.gethostbyaddr(ip_address)
        return host_name
    except socket.herror as e:
        print(f"Error: {e}")
        return None

def get_ip_by_host(host_name):
    try:
        ip_address = socket.gethostbyname(host_name)
        return ip_address
    except socket.gaierror as e:
        print(f"Error: {e}")
        return None

def main():
    while True:
        choice = input("Choose an option (1 for IP to URL, 2 for URL to IP, 0 to exit): ")
        
        if choice == '0':
            break

        if choice == '1':
            ip_address = input("Enter the IP address: ")
            host_name = get_host_by_ip(ip_address)
            if host_name:
                print(f"The URL for IP {ip_address} is: {host_name}")

        elif choice == '2':
            host_name = input("Enter the URL: ")
            ip_address = get_ip_by_host(host_name)
            if ip_address:
                print(f"The IP for URL {host_name} is: {ip_address}")

        else:
            print("Invalid choice. Please enter 1, 2, or 0.")

if __name__ == "__main__":
    main()
