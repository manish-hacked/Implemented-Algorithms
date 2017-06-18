typedef long long int ll;
ll in()
{
    ll _integer=0;
    char _char=0;
    while(_char<48)
        _char=getchar_unlocked();
    while(_char>=48)
    {
        _integer=10*_integer+_char-48;
        _char=getchar_unlocked();
    }
    return _integer;
}
