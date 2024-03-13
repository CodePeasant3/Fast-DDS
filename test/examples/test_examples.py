"""."""
import subprocess

def test_basic_configuration():
    """."""
    ret = False
    out = ''
    try:
        out = subprocess.check_output(
            '@DOCKER_EXECUTABLE@ compose -f basic_configuration.compose.yml up',
            stderr=subprocess.STDOUT,
            shell=True,
            timeout=30
        ).decode().split('\n')

        sent = 0
        received = 0
        for line in out:
            if 'SENT' in line:
                sent += 1
                continue

            if 'RECEIVED' in line:
                received += 1
                continue

        if sent != 0 and received != 0 and sent * 2 == received:
            ret = True
        else:
            raise subprocess.CalledProcessError(1, '')

    except subprocess.CalledProcessError:
        for l in out:
            print(l)
    except subprocess.TimeoutExpired:
        print('TIMEOUT')

    assert(ret)

def test_hello_world():
    """."""
    ret = False
    out = ''
    try:
        out = subprocess.check_output(
            '@DOCKER_EXECUTABLE@ compose -f hello_world.compose.yml up',
            stderr=subprocess.STDOUT,
            shell=True,
            timeout=30
        ).decode().split('\n')

        sent = 0
        received = 0
        for line in out:
            if 'SENT' in line:
                sent += 1
                continue

            if 'RECEIVED' in line:
                received += 1
                continue

        if sent != 0 and received != 0 and sent * 2 == received:
            ret = True
        else:
            raise subprocess.CalledProcessError(1, '')

    except subprocess.CalledProcessError:
        for l in out:
            print(l)
    except subprocess.TimeoutExpired:
        print('TIMEOUT')

    assert(ret)
